#include "CommandHandler.h"
#include "CommandFactory.h"

using namespace std;

namespace fwsync
{

	CommandHandler::CommandHandler()
	{

	}

	CommandHandler::CommandHandler(wstring sCommand)
	{
		CommandFactory::assign(sCommand, this);
	}
}