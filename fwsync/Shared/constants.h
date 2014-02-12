#pragma once
#include <string>

using namespace std;

namespace fwsync
{
	static const int MAXPATH = 256; // Maximale lengte van padnaam
	
	static const string PATHSEPERATOR =
#if defined(__APPLE__) || defined(__linux__)
		"/";
#else
		"\\";
#endif

	static const char* OSRUNNING =
#if defined(__APPLE__) || defined(__linux__)
		"GNU/Linux";
#else
		"Win32";
#endif

	static const int BUFFERSIZE = 20480;

	static const char DELIMITER = '|';

}