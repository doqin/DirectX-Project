#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{
}

Application::~Application()
{
}

VOID Application::SetupPerGameSettings()
{
	// Set Per Game Settings
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}

VOID Application::Initialize()
{	
	Logger::PrintDebugSeparator();
	Logger::PrintLog(L"Application starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time: % s\n", Time::GetDateTimeString().c_str());
	Logger::PrintDebugSeparator();
}

VOID Application::Update()
{
	MessageBox(0, L"I am Running!", 0, 0);
}
