#include "FileWriter.h"

using namespace std;

namespace fwsync
{
	FileWriter::FileWriter(string szPath)
		: m_szPath(szPath)
	{
		m_osFile = ofstream(szPath, ofstream::binary | ofstream::trunc);
		
		if (m_osFile.bad())
		{
			throw("Cannot open file for writing");
		}
	}

	FileWriter::~FileWriter()
	{
		m_osFile.close();
	}

	void FileWriter::readFromSocket(Socket* sSocket)
	{
		char buff[BUFFERSIZE + 1];

		sSocket->readline(buff, BUFFERSIZE);

		int iFileSize = stoi(buff);

		if (iFileSize >= 0)
		{
			int iBytesToRead = iFileSize;

			int iBytesRead;
			while (iBytesToRead > 0)
			{
				try
				{
					iBytesRead = sSocket->read(buff, iBytesToRead > BUFFERSIZE ? BUFFERSIZE : iBytesToRead);
				}
				catch (SocketException& ex)
				{
					m_osFile.close();
					throw ex;
				}

				m_osFile.write(buff, iBytesRead);

				iBytesToRead -= iBytesRead;

				cout << "\rProgress: " << (((long long)(iFileSize - iBytesToRead) * 100) / iFileSize) << "% " << (iFileSize - iBytesToRead) / 1000 << "/" << iFileSize / 1000 << " KB";
			}

			cout << endl << "Done." << endl;
		}
		else
		{
			char errbuff[BUFFERSIZE + 1];
			while (sSocket->readline(errbuff, BUFFERSIZE) > 0)
			{
				cout << errbuff << endl;
			}
		}
	}

	void FileWriter::close()
	{
		m_osFile.close();
	}

}