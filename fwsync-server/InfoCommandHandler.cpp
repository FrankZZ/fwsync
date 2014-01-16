#include "InfoCommandHandler.h"

using namespace std;

namespace fwsync
{

	InfoCommandHandler InfoCommandHandler::m_infoCmdHandler(string("info"));

	InfoCommandHandler::InfoCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	InfoCommandHandler::InfoCommandHandler()
	{

	}

	void InfoCommandHandler::process(Socket* socket, vector<string>& params)
	{
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		localtime_s(&tstruct, &now);

		strftime(buf, sizeof(buf), "%Y%m%d_%X", &tstruct);

		socket->write("FWSync Server 0.1a");
		socket->writeline(buf);
		socket->writeline("");

	}

	CommandHandler* InfoCommandHandler::clone()
	{
		return new InfoCommandHandler();
	}

}