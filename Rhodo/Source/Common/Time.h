#pragma once
#include <string>

namespace Time {
	// Get Current Time in String Format
	std::wstring RHODO_API GetTime(BOOL stripped = FALSE);

	// Get Current Date in String Format
	std::wstring RHODO_API GetDate(BOOL stripped = FALSE);

	// Get Current Date and Time in String Format
	std::wstring RHODO_API GetDateTimeString(BOOL stripped = FALSE);
}