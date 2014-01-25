#pragma once
#include "../../Shared/Models/dirent.h"
#include "../../Shared/constants.h"
#include <string>
#include <vector>
using namespace std;
namespace fwsync
{
	class Directory
	{
		public:
			static void del(string);
			static void create(string);
			static void getListing(string, vector<string>&, bool);
			static bool isDir(string);
			static time_t getLastModifiedTime(string szPath);

		private:
			static DIR* open(string);
	};
}
