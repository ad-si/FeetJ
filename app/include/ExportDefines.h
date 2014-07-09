#pragma once

#include <QtGlobal>

#ifdef Q_OS_WIN
#	ifdef EXPORT_STATIC
#		define MTQ_EXPORT
#		define PLUGIN_EXPORT
#	else
#		ifdef MTQ_DLL
#		   define MTQ_EXPORT	   Q_DECL_EXPORT
#			define PLUGIN_EXPORT  Q_DECL_IMPORT
#		else
#		   ifdef PLUGIN_DLL
#			   define MTQ_EXPORT	   Q_DECL_IMPORT
#			   define PLUGIN_EXPORT  Q_DECL_EXPORT
#		   else
#			   define MTQ_EXPORT	   Q_DECL_IMPORT
#			   define PLUGIN_EXPORT
#		   endif
#	   endif
#	endif
#else
#	define MTQ_EXPORT
#   define PLUGIN_EXPORT
#endif
