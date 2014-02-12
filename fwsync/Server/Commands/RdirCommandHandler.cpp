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
		strsplit(szLine, params, ' ', 2);

		if (params.size() != 2)
		{
			throw ("Syntax error");
		}
		
		vector<string> vListing;
		
		Directory::getListing(params[1], vListing, true);

		socket->writeline("OK");
		for (int i = 0; i < vListing.size(); i++)
			socket->writeline(vListing[i].c_str());

		socket->writeline("");
	}

	CommandHandler* RdirCommandHandler::clone()
	{
		return new RdirCommandHandler();
	}

}