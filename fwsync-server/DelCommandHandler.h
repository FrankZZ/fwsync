#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"
#include "Directory.h"

using namespace std;

namespace fwsync
{

	class DelCommandHandler : public CommandHandler
	{
	private:
		DelCommandHandler();
		DelCommandHandler(wstring);

	public:
		virtual void process(Socket*, vector<wstring>&);
		virtual CommandHandler* clone();

	private:
		static DelCommandHandler m_delCmdHandler;
	};
}
