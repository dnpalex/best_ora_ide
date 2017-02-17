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
    void BeginTextGroup(QString gn);
    void EndTextGroup();
private:

    QSettings textSettings;
};

#endif // SETTINGSUSERTEXT_H
