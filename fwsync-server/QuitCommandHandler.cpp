#include "QuitCommandHandler.h"
namespace fwsync
{

	QuitCommandHandler QuitCommandHandler::m_quitCmdHandler(std::string("quit"));

	QuitCommandHandler::QuitCommandHandler(std::string sCommand) : CommandHandler(sCommand)
	{

	}

	QuitCommandHandler::QuitCommandHandler()
	{

	}

	void QuitCommandHandler::process(Socket* socket, std::vector<std::string>& params)
	{
		socket->writeline("Bye.");
		socket->close();
	}

	CommandHandler* QuitCommandHandler::clone()
	{
		return new QuitCommandHandler();
	}
}