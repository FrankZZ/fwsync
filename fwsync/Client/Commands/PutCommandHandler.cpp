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
		

		FileReader* fw = new FileReader(params[2]);

		fw->writeToSocket(socket);

		delete fw;

	}

	void interrupt(int param)
	{
		remove("test.exe");
	}

	CommandHandler* PutCommandHandler::clone()
	{
		return new PutCommandHandler();
	}
}