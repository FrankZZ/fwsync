#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"

using namespace std;

namespace fwsync
{

	class InfoCommandHandler : public CommandHandler
	{
	private:
		InfoCommandHandler();
		InfoCommandHandler(wstring);

	public:
		virtual void process(Socket*, vector<wstring>&);
		virtual CommandHandler* clone();

	private:
		static InfoCommandHandler m_infoCmdHandler;
	};
}
