#ifndef SETTINGSUSERTEXT_H
#define SETTINGSUSERTEXT_H

#include <QSettings>
#include <QScopedPointer>
#include <QVariant>

class SettingsUser
{
public:
    SettingsUser();

protected:

    QVariant configValue(const QString& group, const QString& key);

private:

    QSettings config;
};

#endif // SETTINGSUSERTEXT_H
