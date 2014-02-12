#pragma once
#if defined(__APPLE__) || defined(__linux__)

#include <dirent.h>

#else

#include "../../Shared/Models/dirent.h"

#endif

#include <string>
#include <fstream>
#include "Socket.h"
#include "../../Shared/constants.h"
#include "../../Shared/Models/Directory.h"

using namespace std;

namespace fwsync
{
	class FileReader
	{
		public:
			FileReader();
			FileReader(string);
			~FileReader();
			int getFileSize();
			void writeToSocket(Socket*);

		private:
			string m_szPath;
			ifstream m_isFile;
	};
}
