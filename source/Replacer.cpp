#include <Replacer.hpp>
#include <Atlas.hpp>

using namespace spamscript;

Replacer::Replacer(const QString& originalText) noexcept {
    m_originalText = originalText;
    srand(static_cast<unsigned int>(time(0)));
}

void Replacer::setOriginalText(const QString& originalText) noexcept {
    m_originalText = originalText;
}
void Replacer::setAtlas(const QSharedPointer<Atlas> atlas) noexcept {
    m_atlas = atlas;
}

QString Replacer::getReplacedText() noexcept {
    auto atlas = m_atlas.get()->getAtlas();
    QString generatedReplacedText = m_originalText;
    for (auto it = atlas.begin(); it != atlas.end(); it++) {
        const auto positions = generateReplacePositions(getIndexes(generatedReplacedText, it.key()));

        for (auto posit = positions.begin(); posit != positions.end(); posit++) {
            if (posit.value() == false)
                continue;
            const auto pos = generatedReplacedText.indexOf(it.key(), posit.key());
            if (pos != -1) {
                generatedReplacedText.replace(pos, it.key().length(), it.value());
            }
        }
    }
    return generatedReplacedText;
}

QList<qsizetype> Replacer::getIndexes(const QString& message, const QString& symbol) noexcept{
    QList<qsizetype> indexes;
    qsizetype pos = message.indexOf(symbol);
    if (pos != -1)
        indexes << pos;
    while(pos != -1) {
        pos = message.indexOf(symbol, pos + 1);
        if (pos != -1)
            indexes << pos;
    }
    return indexes;
}

QMap<qsizetype, bool> Replacer::generateReplacePositions(const QList<qsizetype>& indexes) noexcept {
    QMap<qsizetype, bool> positions;
    for (auto i : indexes) {
        if (rand() % 2 == 0) {
            positions[i] = true;
        } else {
            positions[i] = false;
        }
    }
    return positions;
}