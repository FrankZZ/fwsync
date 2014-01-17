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
			static void del(wstring);
			static void create(wstring);
			static wstring getListing(wstring);
	
		private:
			static WDIR* open(wstring);
	};
}
