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
		if (params.size() != 2)
		{
			throw ("Syntax error");
		}

		cout << "Writing dirlisting" << endl;
		vector<string> vListing;
		Directory::getListing(params[1], vListing, false);
		
		for (int i = 0; i < vListing.size(); i++)
			socket->writeline(vListing[i].c_str());

		cout << "Wrote dirlisting\n";
		socket->writeline("");
	}

	CommandHandler* DirCommandHandler::clone()
	{
		return new DirCommandHandler();
	}

}