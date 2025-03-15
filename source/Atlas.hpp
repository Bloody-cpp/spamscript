#ifndef ATLAS_HEADER
#define ATLAS_HEADER

#include <QtCore>

namespace spamscript {
    class Atlas {
    public:
        Atlas(const QMap<QString, QString>& atlas) noexcept {
            m_atlas = atlas;
        }
        ~Atlas() noexcept = default;
        
        inline QMap<QString, QString>& getAtlas() noexcept {
            return m_atlas;
        }
    private:    
        QMap<QString, QString> m_atlas;
    };
}

#endif /* ATLAS_HEADER */
