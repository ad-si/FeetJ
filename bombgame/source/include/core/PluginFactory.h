#pragma once

#include <QObject>
#include <QSharedPointer>
#include <QMap>
#include <QFile>
#include <QDebug>

#include "utils/Singelton.h"
#include "core/Configuration.h"
#include "ExportDefines.h"

#define MTQ_PLUGIN(PluginT, PluginTypeT) \
    public: \
        static PluginTypeT* createInstance() \
        { \
            return new PluginT(); \
		}

#define MTQ_REGISTER_PLUGIN(PluginT, PluginTypeT) \
	static int __local_id_of_PluginObject = mtq::PluginFactory<PluginTypeT>::instance().registerPlugin<PluginT>(PLUGIN_NAME);

#define MTQ_REGISTER_PLUGINFACTORY(PluginTypeT) \
	PluginFactory<PluginTypeT>::instance().getSharedInstance(""); \
	PluginFactory<PluginTypeT>::instance().createNewInstance(""); \
	PluginFactory<PluginTypeT>::instance().registeredPlugins();

#define MTQ_USE_PLUGINFACTORY(PluginTypeT) \
    namespace mtq { \
        typedef PluginFactory<PluginTypeT> PluginTypeT##Factory; \
        typedef QSharedPointer<PluginTypeT> PluginTypeT##Ptr; \
    }

namespace mtq {

    template <class PluginTypeT>
    class MTQ_EXPORT PluginFactory
    {
        MTQ_SINGELTON(PluginFactory)
    public:
        typedef PluginTypeT* (*CreateInstanceMethod)();
        typedef QSharedPointer<PluginTypeT> PluginTypeTPtr;

        template <class PluginT>
        int registerPlugin(QString pluginName)
        {
            QMutexLocker locker(&m_mutex);

            qDebug() << "Successfully registered plugin: " << pluginName;
            m_instanceMethods.insert(pluginName, &PluginT::createInstance);
            Configuration::instance().registerPluginConfig(pluginName);
            return m_instanceMethods.size() - 1;
        }

        QList<QString> registeredPlugins()
        {
            return m_instanceMethods.keys();
        }

        PluginTypeTPtr createNewInstance(QString pluginName)
        {
            return m_instanceMethods.contains(pluginName) ? PluginTypeTPtr((*m_instanceMethods.find(pluginName))()) : PluginTypeTPtr();
        }

        PluginTypeTPtr getSharedInstance(QString pluginName)
        {
            if (!m_sharedInstances.contains(pluginName)) {
                QMutexLocker locker(&m_mutex);
                if (!m_sharedInstances.contains(pluginName))
                    m_sharedInstances.insert(pluginName, createNewInstance(pluginName));
            }

            return *m_sharedInstances.find(pluginName);
        }

    private:
        PluginFactory() {}

        QMap<QString, CreateInstanceMethod> m_instanceMethods;
        QMap<QString, PluginTypeTPtr> m_sharedInstances;
        QMutex m_mutex;
    };

}
