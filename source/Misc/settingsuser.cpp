#include "settingsuser.h"

SettingsUser::SettingsUser() : config(":/config", QSettings::IniFormat){}

QVariant SettingsUser::configValue(const QString& group, const QString& key)
{
    config.beginGroup(group);
    QVariant val = config.value(key);
    config.endGroup();
    return val;
}
