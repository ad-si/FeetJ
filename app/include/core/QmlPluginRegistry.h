#pragma once

#include <QtQml>

#include "utils/Singelton.h"
#include "ExportDefines.h"

#define MTQ_QML_PLUGIN_DEFAULT_MAJOR_VERSION 1
#define MTQ_QML_PLUGIN_DEFAULT_MINOR_VERSION 0

#define MTQ_QML_PLUGIN_REGISTRATION_VERSION(QObjectT, ModuleName, MajorVersion, MinorVersion) \
	public: \
		static void registerPlugin() \
		{ \
			qmlRegisterType<QObjectT>("mtq." ModuleName, MajorVersion, MinorVersion, #QObjectT); \
		}

#define MTQ_QML_PLUGIN_REGISTRATION(QObjectT, ModuleName) \
	MTQ_QML_PLUGIN_REGISTRATION_VERSION(QObjectT, ModuleName, MTQ_QML_PLUGIN_DEFAULT_MAJOR_VERSION, MTQ_QML_PLUGIN_DEFAULT_MINOR_VERSION)

#define MTQ_QML_REGISTER_PLUGIN(QObjectT) \
	static int __local_id_of_PluginObject = mtq::QmlPluginRegistry::instance().registerPlugin<QObjectT>();

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
