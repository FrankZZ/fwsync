#pragma once
#include <string>

using namespace std;

namespace fwsync
{
	static const int MAXPATH = 256; // Maximale lengte van padnaam
	
	static const wstring PATHSEPERATOR =
#if defined(__APPLE__) || defined(__linux__)
		L"/";
#else
		L"\\";
#endif

	static const wchar_t* OSRUNNING =
#if defined(__APPLE__) || defined(__linux__)
		L"GNU/Linux";
#else
		L"Win32";
#endif

	static const int BUFFERSIZE = 4096;

	static const wchar_t DELIMITER = '|';

}