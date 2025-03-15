#include <OriginalTextInput.hpp>
#include <QtCore>
#include <windows.h>

using namespace spamscript;
using namespace std;

optional<QString> OriginalTextInput::getOriginalText() noexcept {
    QFile file(m_inputFileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return nullopt;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    auto text = in.readAll();
    file.close();
    return text;
}