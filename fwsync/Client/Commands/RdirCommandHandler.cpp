#include "RdirCommandHandler.h"

using namespace std;

namespace fwsync
{

	RdirCommandHandler RdirCommandHandler::m_rdirCmdHandler(string("rdir"));

	RdirCommandHandler::RdirCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	RdirCommandHandler::RdirCommandHandler()
	{

	}

	void RdirCommandHandler::process(Socket* socket, string szLine)
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

	CommandHandler* RdirCommandHandler::clone()
	{
		return new RdirCommandHandler();
	}
}
