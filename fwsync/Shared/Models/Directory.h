#pragma once
#include "../../Shared/Models/dirent.h"
#include "../../Shared/constants.h"
#include "../../Shared/utility.h"
#include <string>
#include <vector>
#include <time.h>
#include <sys/utime.h>
#include <direct.h>
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
			static void setLastModifiedTime(string, int);

		private:
			static DIR* open(string);
	};
}
