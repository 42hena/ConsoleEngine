#ifndef __CORE_H__
#define __CORE_H__

#ifdef BUILD_ENGINE_DLL
#define ENGINE_API __declspec(dllexport)

#else
#define ENGINE_API __declspec(dllimport)

#endif

#endif
