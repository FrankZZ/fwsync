#include "PutCommandHandler.h"

using namespace std;

namespace fwsync
{

	PutCommandHandler PutCommandHandler::m_putCmdHandler(string("put"));

	PutCommandHandler::PutCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	PutCommandHandler::PutCommandHandler()
	{

	}

	void PutCommandHandler::process(Socket* socket, string szLine)
	{
		vector<string> params = vector<string>();
		strsplit(szLine, params, ' ', 3);

		if (params.size() != 3)
			throw("SYNTAX: PUT [local file] [remote file]");

		Directory::createSubDirectories(params[2], true);

		FileWriter* fw = new FileWriter(params[2]);
		
		socket->writeline("OK");

		fw->readFromSocket(socket);

		delete fw;

		socket->writeline("");

	}

	CommandHandler* PutCommandHandler::clone()
	{
		return new PutCommandHandler();
	}
}
