#pragma once

#include <QVariant>
#include <QSettings>

#include "utils/Singelton.h"
#include "ExportDefines.h"

namespace mtq {

    struct ConfigurationDetail;

    class MTQ_EXPORT Configuration
    {
        MTQ_SINGELTON(Configuration)
    public:
        bool contains(const QString key) const;
        bool contains(const QString group, const QString key) const;
        QVariant value(const QString key) const;
        QVariant value(const QString group, const QString key) const;

        void registerPluginConfig(const QString pluginName);
        void loadPluginConfigs();

    private:
        Configuration();
        ~Configuration();

        void setupTempConfig();
        void setupDefaultConfig();
        void setupFileConfig();

        void mergeConfig(const QString group, QSettings *config, bool overwrite = false);

        ConfigurationDetail *m_detail;
    };

}
