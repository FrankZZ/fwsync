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

	void DirCommandHandler::process(Socket* socket, string szLine)
	{
		vector<string> params = vector<string>();
		strsplit(szLine, params, '|', 2);

		if (params.size() != 2)
			throw("SYNTAX: DIR [remote dir]");

		socket->writeline(szLine);

		char line[MAXPATH + 1];

		socket->readline(line, MAXPATH);

		if (strcmp(line, "OK") != 0)
		{
			while (socket->readline(line, MAXPATH) > 0)
			{
				cout << line << endl;
			}
			throw("Error occured");
		}
			

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
