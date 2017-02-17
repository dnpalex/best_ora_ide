#include "settingsuser.h"

SettingsUser::SettingsUser() : textSettings(":/general", QSettings::IniFormat){}

QVariant SettingsUser::textValue(QString key)
{
    return textSettings.value(key, "Default Text");
}

void SettingsUser::BeginTextGroup(QString gn)
{
    textSettings.beginGroup(gn);
}

void SettingsUser::EndTextGroup()
{
    textSettings.endGroup();
}

