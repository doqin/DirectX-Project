#pragma once


#ifdef WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define RHODO_API __declspec(dllexport)
#else
	#define RHODO_API __declspec(dllimport)
#endif