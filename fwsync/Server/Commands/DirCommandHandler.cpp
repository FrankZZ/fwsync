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
		strsplit(szLine, params, ' ', 2);

		if (params.size() != 2)
		{
			throw ("Syntax error");
		}
		
		vector<string> vListing;
		
		Directory::getListing(params[1], vListing, false);

		socket->writeline("OK");
		for (int i = 0; i < vListing.size(); i++)
			socket->writeline(vListing[i].c_str());

		socket->writeline("");
	}

	CommandHandler* DirCommandHandler::clone()
	{
		return new DirCommandHandler();
	}

}