#include "InfoCommandHandler.h"

namespace fwsync
{

	InfoCommandHandler InfoCommandHandler::m_infoCmdHandler(std::string("info"));

	InfoCommandHandler::InfoCommandHandler(std::string sCommand) : CommandHandler(sCommand)
	{

	}

	InfoCommandHandler::InfoCommandHandler()
	{

	}

	void InfoCommandHandler::process(Socket* socket, std::vector<std::string>& params)
	{
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		localtime_s(&tstruct, &now);

		strftime(buf, sizeof(buf), "%Y%m%d_%X", &tstruct);

		socket->write("FWSync Server 0.1a");
		socket->writeline(buf);

	}

	CommandHandler* InfoCommandHandler::clone()
	{
		return new InfoCommandHandler();
	}

}