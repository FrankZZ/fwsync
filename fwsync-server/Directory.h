#pragma once
#include "dirent.h"
#include "constants.h"
#include <string>
#include <map>
using namespace std;
namespace fwsync
{
	class Directory
	{
		public:
			static void del(string);
			static void create(string);
			static string getListing(string);
	
		private:
			static DIR* open(string);
	};
}
