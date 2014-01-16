#pragma once
#include <string>

namespace fwsync
{
	static const int MAXPATH = 256; // Maximale lengte van padnaam
	
	static const std::string PATHSEPERATOR =
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

	static const int BUFFERSIZE = 4096;

}