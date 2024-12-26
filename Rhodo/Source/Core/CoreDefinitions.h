#pragma once

#ifdef BUILD_DLL
	#define RHODO_API __declspec(dllexport)
#else
	#define RHODO_API __declspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)