#include "DirectX-Project.h"
#include "Engine/Simulation.h"
#include "Platform/Win32/WinEntry.h"

class DirectXProject : public Rhodo::Simulation {

	// Application

public:
	// Application Contructor
	DirectXProject() {}

	// Application Deconstructor
	~DirectXProject() {}

public:

	// Called to Setup Per Game Settings
	VOID SetupPerGameSettings();

	// Called to Initialize the Application
	VOID Initialize() {}

	// Game Loop - Called on a Loop While the Application is Running
	VOID Update();
};

ENTRYAPP(DirectXProject)

VOID DirectXProject::SetupPerGameSettings()
{
	// Set Per Game Settings
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	// PerGameSettings::SetSplashURL(IDS_SPLASHURL);
}

VOID DirectXProject::Update()
{
	// MessageBox(0, L"I am Running!", L"Message Box", 0);
}