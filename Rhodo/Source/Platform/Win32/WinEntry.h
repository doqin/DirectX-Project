#include "Rhodo.h"

#include "IApplication.h"
#include "Common/CmdLineArgs.h"
#include "Engine/SplashScreen.h"

extern Win32::IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	auto EntryApp = EntryApplication();

	PerGameSettings GameSettings;
	EntryApp->SetupPerGameSettings();

	CmdLineArgs::ReadArguments();

	Logger logger;

	SplashScreen::Open();
	// SplashScreen::AddMessage(L"Starting Application...");

	EntryApp->PreInitialize();

	EntryApp->Initialize();

	MSG msg = { 0 };

	while (msg.message != WM_QUIT) {
		// Process Messages
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			EntryApp->Update();
		}
	}

	return 0;
}