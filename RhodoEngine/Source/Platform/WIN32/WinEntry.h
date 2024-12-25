#include "RhodoEngine.h"
#include "IApplication.h"

extern IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	auto EntryApp = EntryApplication();

	PerGameSettings GameSettings;
	EntryApp->SetupPerGameSettings();

	Logger logger;
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