#include "GetCommandHandler.h"
namespace fwsync
{

	GetCommandHandler GetCommandHandler::m_getCmdHandler(std::string("get"));

	GetCommandHandler::GetCommandHandler(std::string sCommand) : CommandHandler(sCommand)
	{

	}

	GetCommandHandler::GetCommandHandler()
	{

	}

	void GetCommandHandler::process(Socket* socket, std::vector<std::string>& params)
	{

	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}