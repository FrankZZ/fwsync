#pragma once
#include "../../Shared/Models/dirent.h"
#include <string>
#include <fstream>
#include "Socket.h"
#include "../../Shared/constants.h"

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
