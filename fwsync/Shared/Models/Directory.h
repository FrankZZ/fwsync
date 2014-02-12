#pragma once
#if defined(__APPLE__) || defined(__linux__)

#include <utime.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#else
//windows
#include "../../Shared/Models/dirent.h"
#include <sys/utime.h>
#include <direct.h>

#endif


#include "../../Shared/constants.h"
#include "../../Shared/utility.h"
#include <string>
#include <vector>
#include <time.h>


using namespace std;
namespace fwsync
{
	class Directory
	{
	public:
		static void del(string);

		static void getListing(string, vector<string>&, bool);

		static bool isDir(string);
		static bool isFile(string);

		static void createSubDirectories(string, bool);

		static time_t getLastModifiedTime(string szPath);
		static void setLastModifiedTime(string, time_t);

	private:
		static DIR* open(string);
	};
}
