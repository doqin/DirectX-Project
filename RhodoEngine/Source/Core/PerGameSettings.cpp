#include "RhodoEngine.h"

PerGameSettings* PerGameSettings::inst;

PerGameSettings::PerGameSettings()
{
	inst = this;

	wcscpy_s(m_GameName, L"undefined");
	wcscpy_s(m_ShortName, L"undefined");
	wcscpy_s(m_BootTime, Time::GetDateTimeString(TRUE).c_str());
}

PerGameSettings::~PerGameSettings()
{
}
