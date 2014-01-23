#pragma once
#include "dirent.h";
#include <string>;
#include <fstream>;
#include "Socket.h";
#include "constants.h";

using namespace std;

namespace fwsync
{
	class FileReader
	{
		public:
			FileReader(string);
			~FileReader();
			int getFileSize();
			void writeToSocket(Socket*);
			void close();

		private:
			string m_szPath;
			ifstream m_isFile;
	};
}
