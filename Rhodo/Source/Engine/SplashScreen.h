#pragma once

#include "Platform/Win32/Window.h"

namespace SplashScreen {

	VOID RHODO_API Open();
	VOID RHODO_API Close();
	VOID RHODO_API AddMessage(CONST WCHAR* message);

}

class RHODO_API SplashWindow : public Win32::Window {

public:
	SplashWindow();
	~SplashWindow();

	virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};