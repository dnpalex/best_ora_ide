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

    QVariant textValue(QString key);
    QVariant configValue(QString key);

    void BeginTextGroup(QString gn);
    void EndTextGroup();

    void BeginConfigGroup(QString gn);
    void EndConfigGroup();

private:

    QSettings textSettings;
    QSettings config;
};

#endif // SETTINGSUSERTEXT_H
