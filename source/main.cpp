#include <Atlas.hpp>
#include <Replacer.hpp>
#include <OriginalTextInput.hpp>
#include <QtCore>
#include <QtWidgets>
#include <windows.h>

using namespace std;

void SetClipboardText(const QString& text) {
    std::wstring wText = text.toStdWString();
    if (OpenClipboard(NULL)) {
        EmptyClipboard();

        HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, (wText.size() + 1) * sizeof(wchar_t));
        if (hGlob) {
            wchar_t* pGlobal = static_cast<wchar_t*>(GlobalLock(hGlob));
            memcpy(pGlobal, wText.c_str(), (wText.size() + 1) * sizeof(wchar_t));
            GlobalUnlock(hGlob);

            SetClipboardData(CF_UNICODETEXT, hGlob);
        }
        CloseClipboard();
    }
}

int main(int argc, char** argv){
    CoInitialize(NULL);
    QApplication app(argc, argv);
    const QSharedPointer<spamscript::Atlas> atlas(new spamscript::Atlas({
        {"с", "c"},
        {"е", "e"},
        {"о", "o"},
        {"р", "p"},
        {"х", "x"},
        {"а", "a"}
    }));

    qDebug() << "Spam script by darkmind, v0.1.0";
    spamscript::OriginalTextInput input("input.txt");
    optional<QString> originalText = input.getOriginalText();
    if (!originalText.has_value()) {
        qDebug() << "Error reading input file";
        QThread::msleep(5000);
        return 1;
    }

    qDebug() << "Succesfull read input file";
    spamscript::Replacer replacer(originalText.value());
    replacer.setAtlas(atlas);
    qDebug() << "Replacer created";

    while(true) {
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(0x56) & 0x8000) {
            auto text = replacer.getReplacedText();
            SetClipboardText(text);
            qDebug() << "Succesfull handled ctrl + v";
            QThread::msleep(500);
        }
        QThread::msleep(20);
    }
    return app.exec();
}
