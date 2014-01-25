#include "QuitCommandHandler.h"

using namespace std;

namespace fwsync
{

	QuitCommandHandler QuitCommandHandler::m_quitCmdHandler(string("quit"));

	QuitCommandHandler::QuitCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	QuitCommandHandler::QuitCommandHandler()
	{

	}

	void QuitCommandHandler::process(Socket* socket, vector<string>& params)
	{
		socket->writeline("Bye.");
		socket->close();
	}

	CommandHandler* QuitCommandHandler::clone()
	{
		return new QuitCommandHandler();
	}
}