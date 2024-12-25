#include "RhodoEngine.h"
#include <ctime>
#include <sstream>
#include <iomanip>

// Get Time in Format '00:00:00'
// Stripped = 000000
std::wstring Time::GetTime(BOOL stripped) {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%T");

	std::wstring timeString = wss.str();

	if (stripped) {
		std::wstring chars = L":";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}

// Get Date in Format '00/00/00'
// Stripped = 000000
std::wstring Time::GetDate(BOOL stripped) {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%d/%m/%y");
	std::wstring dateString = wss.str();
	if (stripped) {
		std::wstring chars = L"/";
		for (WCHAR c : chars) {
			dateString.erase(std::remove(dateString.begin(), dateString.end(), c), dateString.end());
		}
	}
	return dateString;
}

// Get Date and Time in Format '00/00/00 00:00:00'
// Stripped = 000000000000
std::wstring Time::GetDateTimeString(BOOL stripped) {
	
	std::wstring timeString = GetDate(stripped) + L" " + GetTime(stripped);

	if (stripped) {
		std::wstring chars = L" ";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}