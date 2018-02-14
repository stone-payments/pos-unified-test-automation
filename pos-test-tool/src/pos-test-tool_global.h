#ifndef POSTESTTOOL_GLOBAL_H
#define POSTESTTOOL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(POSTESTTOOL_LIBRARY)
#  define POSTESTTOOLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define POSTESTTOOLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // POSTESTTOOL_GLOBAL_H