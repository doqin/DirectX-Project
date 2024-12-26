#include "Rhodo.h"
#include "SplashScreen.h"

#include "Platform/Win32/Win32Utils.h"

namespace SplashScreen {

#define WM_OUTPUTMESSAGE (WM_USER + 1)

	SplashWindow* m_SplashWindow;

	VOID Open()
	{
		if (m_SplashWindow == nullptr)
		{
			m_SplashWindow = new SplashWindow();
		}
	}
	VOID Close()
	{

	}
	VOID AddMessage(CONST WCHAR* message)
	{
		PostMessage(m_SplashWindow->GetHandle(), WM_OUTPUTMESSAGE, (WPARAM)message, 0);
	}
}

SplashWindow::SplashWindow()
	: Win32::Window(L"SplashScreen", L"SplashScreen", NULL, 500, 600)
{
	wcscpy_s(m_outputMessage, L"SplashScreen Starting...");
	Win32::Window::RegisterNewClass();
	Win32::Window::Initialize();
}

SplashWindow::~SplashWindow()
{

}

LRESULT SplashWindow::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_PAINT: {
			HBITMAP hBitmap;
			HDC hdc, hmemdc;
			PAINTSTRUCT ps;

			hdc = BeginPaint(hWnd, &ps);

			Win32::Utils::AddBitmap(PerGameSettings::SplashURL(), hdc);

			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(241, 226, 197));

			if (Engine::GetMode() != EngineMode::RELEASE) {
				std::wstring engineModeText = Engine::EngineModeToString() + L" Mode";
				SetTextAlign(hdc, TA_RIGHT);
				TextOut(hdc, m_Width - 15, 15, engineModeText.c_str(), wcslen(engineModeText.c_str()));
			}


			SetTextAlign(hdc, TA_CENTER);
			TextOut(hdc, m_Width / 2, m_Height - 30, m_outputMessage, wcslen(m_outputMessage));
			EndPaint(hWnd, &ps);
		}
		break;
		case WM_OUTPUTMESSAGE: {
			wcscpy_s(m_outputMessage, (WCHAR*)wParam);
			RedrawWindow(GetHandle(), NULL, NULL, RDW_INVALIDATE);
			return 0;
		}
		break;
	}


	return CommonMessageHandler(hWnd, msg, wParam, lParam);
}
