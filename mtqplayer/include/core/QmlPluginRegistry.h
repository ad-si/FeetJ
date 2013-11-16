#pragma once

#include <QtQml>

#include "utils/Singelton.h"
#include "ExportDefines.h"

#define QML_PLUGIN_DEFAULT_MAJOR_VERSION 1
#define QML_PLUGIN_DEFAULT_MINOR_VERSION 0

#define QML_PLUGIN_REGISTRATION_VERSION(QObjectT, ModuleName, MajorVersion, MinorVersion) \
    public: \
        static void registerPlugin() \
        { \
            qmlRegisterType<QObjectT>("mtq." ModuleName, MajorVersion, MinorVersion, #QObjectT); \
        }

#define QML_PLUGIN_REGISTRATION(QObjectT, ModuleName) \
    QML_PLUGIN_REGISTRATION_VERSION(QObjectT, ModuleName, QML_PLUGIN_DEFAULT_MAJOR_VERSION, QML_PLUGIN_DEFAULT_MINOR_VERSION)

#define QML_REGISTER_PLUGIN(QObjectT) \
    static int __local_id_of_PluginObject = QmlPluginRegistry::instance().registerPlugin<QObjectT>();

namespace mtq {

    struct QmlPluginRegistryDetail;

    class MTQ_EXPORT QmlPluginRegistry
    {
        MTQ_SINGELTON(QmlPluginRegistry)
    public:
        typedef void (*RegistrationMethod)();

        // this method needs to stay in the header file due to dll-linkage reasons
        template <class QObjectT>
        int registerPlugin()
        { return registerPluginPrivate(&QObjectT::registerPlugin); }

        void runAvailableRegistrations();

    private:
        QmlPluginRegistry();
        int registerPluginPrivate(RegistrationMethod registration);

        QmlPluginRegistryDetail *m_detail;
    };

}
