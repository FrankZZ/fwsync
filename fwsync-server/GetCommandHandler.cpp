#include "GetCommandHandler.h"

using namespace std;

namespace fwsync
{

	GetCommandHandler GetCommandHandler::m_getCmdHandler(wstring(L"get"));

	GetCommandHandler::GetCommandHandler(wstring sCommand) : CommandHandler(sCommand)
	{

	}

	GetCommandHandler::GetCommandHandler()
	{

	}

	void GetCommandHandler::process(Socket* socket, vector<wstring>& params)
	{
		if (params.size() < 2)
		{
			socket->writeline("-1");
			throw(L"Syntax error");
		}
		
		ifstream isFile(params[1], ifstream::binary);

		if (!isFile.is_open())
		{
			socket->writeline("-1");
			throw(L"cannot open file");
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

			wcout << "\rProgress: " << (((long long)(iFileSize - iBytesToRead) * 100) / iFileSize) << "% " << (iFileSize - iBytesToRead) / 1000 << "/" << iFileSize / 1000 << " KB";
		}
		wcout << endl;
		
		isFile.close();

	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}
