#pragma once
#include "../../Shared/Models/dirent.h"
#include <string>
#include <fstream>
#include "Socket.h"
#include "../../Shared/constants.h"
#include "../../Shared/Models/Directory.h"
#include "SocketException.h"

using namespace std;

namespace fwsync
{
	class FileWriter
	{
	public:
		FileWriter(string);
		~FileWriter();
		void readFromSocket(Socket*);
		void close();

	private:
		string m_szPath;
		ofstream m_osFile;
	};
}
