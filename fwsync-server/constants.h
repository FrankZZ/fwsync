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

	static const int BUFFERSIZE = 1024;

}