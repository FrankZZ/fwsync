#include "GetCommandHandler.h"

using namespace std;

namespace fwsync
{

	GetCommandHandler GetCommandHandler::m_getCmdHandler(string("get"));

	GetCommandHandler::GetCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	GetCommandHandler::GetCommandHandler()
	{

	}

	void GetCommandHandler::process(Socket* socket, vector<string>& params)
	{
		ifstream isFile(params[1], ifstream::binary);

		if (!isFile.is_open())
		{
			socket->writeline("-1");
			throw("cannot open file");
		}

		char buff[BUFFERSIZE];

		int iFileSize;

		isFile.seekg(0, isFile.end);
		iFileSize = isFile.tellg();
		isFile.seekg(0, isFile.beg);
		
		// Send total size to client
		socket->writeline(to_string(iFileSize).c_str());
		
		int iBytesToRead = iFileSize;

		while (iBytesToRead > 0)
		{
			int iBytesToReadNow = iBytesToRead > BUFFERSIZE ? BUFFERSIZE : iBytesToRead;

			isFile.read(buff, iBytesToReadNow);
			
			socket->write(buff, isFile.gcount());

			iBytesToRead -= isFile.gcount();

			cout << "\rProgress: " << (((long long)(iFileSize - iBytesToRead) * 100) / iFileSize) << "% " << (iFileSize - iBytesToRead) / 1000 << "/" << iFileSize / 1000 << " KB";
		}
		cout << endl;
		
		isFile.close();

	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}
