#include "FileReader.h"

using namespace std;

namespace fwsync
{
	FileReader::FileReader(string szPath)
		: m_szPath(szPath)
		, m_isFile(m_szPath, ifstream::binary)
	{

		if (!m_isFile.is_open())
		{
			throw("cannot open file");
		}
	}

	FileReader::~FileReader()
	{
		if (m_isFile.is_open())
			m_isFile.close();
	}

	int FileReader::getFileSize()
	{
		int iFileSize;

		m_isFile.seekg(0, m_isFile.end);
		iFileSize = m_isFile.tellg();
		m_isFile.seekg(0, m_isFile.beg);

		return iFileSize;
	}

	void FileReader::writeToSocket(Socket* sSocket)
	{
		if (!m_isFile.is_open())
		{
			sSocket->writeline("-1");
			throw("cannot open file");
		}
		cout << "Sending " << m_szPath << endl;
		// Send total size to client
		int iFileSize = this->getFileSize();

		sSocket->writeline(to_string(iFileSize).c_str());
		time_t tim = Directory::getLastModifiedTime(m_szPath);
		sSocket->writeline(to_string(tim).c_str());

		int iBytesToRead = iFileSize;
		char buff[BUFFERSIZE];

		while (iBytesToRead > 0)
		{
			int iBytesToReadNow = iBytesToRead > BUFFERSIZE ? BUFFERSIZE : iBytesToRead;

			m_isFile.read(buff, iBytesToReadNow);

			sSocket->write(buff, m_isFile.gcount());

			iBytesToRead -= m_isFile.gcount();

			cout << "\rProgress: " << (((long long)(iFileSize - iBytesToRead) * 100) / iFileSize) << "% " << (iFileSize - iBytesToRead) / 1000 << "/" << iFileSize / 1000 << " KB";
		}
		cout << endl << "Done." << endl;
	}
}