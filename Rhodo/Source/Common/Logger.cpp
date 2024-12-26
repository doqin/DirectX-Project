#include "Rhodo.h"
#include <fstream>
#include <ShlObj.h>

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{
}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	// Write to File (%Appdata%/$(ApplicationName)/Log/$(ApplicationName)$(Date)$(Time).txt)

	std::wfstream outfile;

	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		std::wstring s = buf;
		outfile << L"[" << Time::GetDateTimeString() << L"]\t" << s << std::endl;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(0, L"Failed to Open Log File!", L"Log Error", MB_OK);
	}
}

// Get and Create Log Directory at %AppData%/Roaming/$(ApplicationName)/Log
std::wstring Logger::LogDirectory()
{
	WCHAR Path[1024];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, PerGameSettings::GameName()); // Replace with your application name
	CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

std::wstring Logger::LogFile() 
{
	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::BootTime());
	wcscat_s(File, L".log");
	return File;
}

VOID Logger::PrintDebugSeparator()
{
	std::wstring s = L"\n-----------------------------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		outfile << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(0, L"Failed to Open Log File!", L"Log Error", MB_OK);
	}
#endif

}
