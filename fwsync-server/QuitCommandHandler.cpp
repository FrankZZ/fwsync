#include "QuitCommandHandler.h"
namespace fwsync
{

	QuitCommandHandler QuitCommandHandler::m_quitCmdHandler(wstring(L"quit"));

	QuitCommandHandler::QuitCommandHandler(wstring sCommand) : CommandHandler(sCommand)
	{

	}

	QuitCommandHandler::QuitCommandHandler()
	{

	}

	void QuitCommandHandler::process(Socket* socket, vector<wstring>& params)
	{
		socket->writeline(L"Bye.");
		socket->close();
	}

	CommandHandler* QuitCommandHandler::clone()
	{
		return new QuitCommandHandler();
	}
}