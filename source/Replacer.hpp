#ifndef REPLACER_HEADER
#define REPLACER_HEADER

#include <QtCore>

namespace spamscript {
    class Atlas;
    class Replacer {
    public:
        Replacer() noexcept = default;
        Replacer(const QString& originalText) noexcept;
        ~Replacer() noexcept = default;

        void setOriginalText(const QString& originalText) noexcept;
        void setAtlas(const QSharedPointer<Atlas> atlas) noexcept;
        QString getReplacedText() noexcept;
    private:
        QList<qsizetype> getIndexes(const QString& message, const QString& symbol) noexcept;
        QMap<qsizetype, bool> generateReplacePositions(const QList<qsizetype>& indexes) noexcept;

        QSharedPointer<Atlas> m_atlas;
        QString m_originalText;
    };
}

#endif /* REPLACER_HEADER */
