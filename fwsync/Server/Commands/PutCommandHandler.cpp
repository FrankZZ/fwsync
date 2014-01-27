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

	void PutCommandHandler::process(Socket* socket, vector<string>& params)
	{
		if (params.size() != 3)
			throw("SYNTAX: PUT [local file] [remote file]");


		FileWriter* fw = new FileWriter(params[2]);

		fw->readFromSocket(socket);

		delete fw;

	}

	CommandHandler* PutCommandHandler::clone()
	{
		return new PutCommandHandler();
	}
}
