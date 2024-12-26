#pragma once

class RHODO_API REngine;

namespace Engine {
	enum EngineMode : INT {
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	extern REngine g_RhodoEngine;

	VOID RHODO_API SetMode(EngineMode mode);
	EngineMode RHODO_API GetMode();

	std::wstring RHODO_API EngineModeToString();
}

using namespace Engine;
class RHODO_API REngine {

public:
	REngine();
	~REngine();

private:
	EngineMode m_EngineMode;

public:
	EngineMode GetEngineMode();
	VOID SetEngineMode(EngineMode mode);
};