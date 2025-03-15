#ifndef ORIGINALTEXTINPUT_HEADER
#define ORIGINALTEXTINPUT_HEADER

#include <QtCore>
#include <optional>

namespace spamscript {
    class OriginalTextInput {
    public:
        OriginalTextInput(const QString& inputFileName) noexcept {
            m_inputFileName = inputFileName;
        }
        ~OriginalTextInput() noexcept {}

        std::optional<QString> getOriginalText() noexcept;
    private:
        QString m_inputFileName;
    };
}

#endif /* ORIGINALTEXTINPUT_HEADER */
