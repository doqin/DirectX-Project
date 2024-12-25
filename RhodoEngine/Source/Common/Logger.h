#pragma once

#include <string>

class RHODO_API Logger {
	// Getters and Setters for Singleton Static Class
public:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }

	// Constructor
public:
	Logger();
	~Logger();

	// Print to Log File
	static VOID PrintLog(const WCHAR* fmt, ...);

	static std::wstring LogDirectory();

	static std::wstring LogFile();

	// Print a Line of '-' to the Log File
	static VOID PrintDebugSeparator();
};