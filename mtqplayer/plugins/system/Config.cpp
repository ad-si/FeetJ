#include "Config.h"

#include "core/Configuration.h"

//We need to register this Type in QML
QML_REGISTER_PLUGIN(Config)

bool Config::contains(const QString key) const
{
    return Configuration::instance().contains(key);
}

bool Config::contains(const QString group, const QString key) const
{
    return Configuration::instance().contains(group, key);
}

QVariant Config::value(const QString key) const
{
    return Configuration::instance().value(key);
}

QVariant Config::value(const QString group, const QString key) const
{
    return Configuration::instance().value(group, key);
}
