#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QObject>
#include <QString>
#include <QMap>

class JsonManager : public QObject
{
public:
    JsonManager();
    void saveOption(const QString& key, const QString& path);
    QString loadOption(const QString& key) const;

private:
    QString m_option;
};

#endif
