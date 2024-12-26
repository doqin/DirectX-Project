#include "Rhodo.h"

namespace Engine {

	REngine g_RhodoEngine;

	VOID RHODO_API SetMode(EngineMode mode)
	{
		g_RhodoEngine.SetEngineMode(mode);
	}

	EngineMode RHODO_API GetMode()
	{
		return g_RhodoEngine.GetEngineMode();
	}

	std::wstring RHODO_API EngineModeToString()
	{
		switch (Engine::GetMode()) {
		case EngineMode::DEBUG:		return L"Debug";
		case EngineMode::RELEASE:	return L"Release";
		case EngineMode::EDITOR:	return L"Editor";
		case EngineMode::SERVER:	return L"Server";
		default:					return L"None";
		}
	}

}

REngine::REngine()
{
#ifdef _DEBUG
	m_EngineMode = EngineMode::DEBUG;
#else
	m_EngineMode = EngineMode::RELEASE;
#endif
}

REngine::~REngine()
{
}

EngineMode REngine::GetEngineMode()
{
	return m_EngineMode;
}

VOID REngine::SetEngineMode(EngineMode mode)
{
	m_EngineMode = mode;
}
