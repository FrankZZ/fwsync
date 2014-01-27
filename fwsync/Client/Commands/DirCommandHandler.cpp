#include "DirCommandHandler.h"

using namespace std;

namespace fwsync
{

	DirCommandHandler DirCommandHandler::m_dirCmdHandler(string("dir"));

	DirCommandHandler::DirCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	DirCommandHandler::DirCommandHandler()
	{

	}

	void DirCommandHandler::process(Socket* socket, vector<string>& params)
	{
		char line[MAXPATH + 1];
		vector<string> vsEntry = vector<string>();

		while (socket->readline(line, MAXPATH) > 0)
		{
			strsplit(line, vsEntry, '|');
			
			if (vsEntry.size() == 2) // It's a file with modtime
				cout << "<FILE> " << vsEntry[0] << endl;
			else if (vsEntry.size() == 1)
				cout << "<DIR > " << vsEntry[0] << endl;

			vsEntry.clear();
		}
	}

	CommandHandler* DirCommandHandler::clone()
	{
		return new DirCommandHandler();
	}
}
