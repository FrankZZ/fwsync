#include "DirCommandHandler.h"

using namespace std;

namespace fwsync
{

	DirCommandHandler DirCommandHandler::m_dirCmdHandler(wstring(L"dir"));

	DirCommandHandler::DirCommandHandler(wstring sCommand) : CommandHandler(sCommand)
	{

	}

	DirCommandHandler::DirCommandHandler()
	{

	}

	void DirCommandHandler::process(Socket* socket, vector<wstring>& params)
	{
		if (params.size() != 2)
		{
			throw (L"Syntax error");
		}

		wcout << "Writing dirlisting\n";
		socket->writeline(Directory::getListing(params[1]).c_str());
		wcout << "Wrote dirlisting\n";
		socket->writeline(L"");
	}

	CommandHandler* DirCommandHandler::clone()
	{
		return new DirCommandHandler();
	}

}