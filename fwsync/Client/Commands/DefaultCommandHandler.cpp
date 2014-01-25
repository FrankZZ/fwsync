#include "DefaultCommandHandler.h"

using namespace std;

namespace fwsync
{

	DefaultCommandHandler DefaultCommandHandler::m_defaultCmdHandler(string("DEFAULT"));

	DefaultCommandHandler::DefaultCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	DefaultCommandHandler::DefaultCommandHandler()
	{

	}

	void DefaultCommandHandler::process(Socket* socket, vector<string>& params)
	{
		char line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH) > 0)
		{
			cout << line << endl;
		}
		
	}

	CommandHandler* DefaultCommandHandler::clone()
	{
		return new DefaultCommandHandler();
	}

}