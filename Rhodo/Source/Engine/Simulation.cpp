#include "Rhodo.h"
#include "Simulation.h"
#include "Engine/SplashScreen.h"

Rhodo::Simulation::Simulation()
{
}

Rhodo::Simulation::~Simulation()
{
}

VOID Rhodo::Simulation::PreInitialize()
{
	Logger::PrintDebugSeparator();

	Logger::PrintLog(L"Application starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::PrintLog(L"Engine Mode: %s\n", Engine::EngineModeToString().c_str());

	Logger::PrintDebugSeparator();

	SplashScreen::Open();
}
