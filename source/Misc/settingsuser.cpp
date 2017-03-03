#include "settingsuser.h"

SettingsUser::SettingsUser() : textSettings(":/general", QSettings::IniFormat), config(":/config.ini", QSettings::IniFormat){}

QVariant SettingsUser::textValue(QString key)
{
    return textSettings.value(key, "Default Text");
}

QVariant SettingsUser::configValue(QString key)
{
    return config.value(key);
}

void SettingsUser::BeginTextGroup(QString gn)
{
    textSettings.beginGroup(gn);
}

void SettingsUser::EndTextGroup()
{
    textSettings.endGroup();
}

void SettingsUser::BeginConfigGroup(QString gn)
{
    config.beginGroup(gn);
}

void SettingsUser::EndConfigGroup()
{
    config.endGroup();
}

