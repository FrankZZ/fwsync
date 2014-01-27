#include "Directory.h"

using namespace std;

namespace fwsync
{
	void Directory::del(string)
	{

	}

	DIR* Directory::open(string szPath)
	{
		DIR* pDir = NULL;

		pDir = opendir(szPath.c_str());

		if (pDir == NULL)
		{
			delete pDir;
			throw("Directory cannot be opened");
		}

		return pDir;
	}

	void Directory::getListing(string szPath, vector<string>& vListing, bool bRecursive)
	{

		DIR* pDir = Directory::open(szPath);

		struct dirent* pEnt = NULL;

		int count = 0;
		while (pEnt = readdir(pDir))
		{
			if (strcmp(pEnt->d_name, ".") == 0 || strcmp(pEnt->d_name, "..") == 0)
				continue;

			string szCurrent(szPath);
			szCurrent.append(PATHSEPERATOR);
			szCurrent.append(pEnt->d_name);

			if (bRecursive && isDir(szCurrent))
			{
				getListing(szCurrent, vListing, true);
			}

			if (isFile(szCurrent))
			{
				int iLastModified = getLastModifiedTime(szCurrent);
				szCurrent.append("|");
				szCurrent.append(to_string(iLastModified));
			}

			vListing.push_back(szCurrent);
			count++;
		}

		delete pEnt;
		delete pDir;
	}

	bool Directory::isDir(string szPath)
	{
		struct stat s;

		if (stat(szPath.c_str(), &s) == 0)
			return s.st_mode & S_IFDIR;
		else
			throw("Can't stat dir");
	}

	void Directory::createSubDirectories(string szPath, bool bIgnoreLastPart)
	{
		vector<string> vsSubDirectories = vector<string>();
		
		//TODO Use PATHSEPERATOR value
		strsplit(szPath, vsSubDirectories, '\\');
		
		if (vsSubDirectories.size() < 2)
			throw("Incorrect path syntax");

		bool bDirectoryExists = FALSE;
		string sCurrentDirectory(vsSubDirectories[0]);

		// Except first slot (drive letter, windows)
		for (int i = 1; i < (bIgnoreLastPart ? vsSubDirectories.size() -  1: vsSubDirectories.size()); i++)
		{
			sCurrentDirectory.append(PATHSEPERATOR);
			sCurrentDirectory.append(vsSubDirectories[i]);

			try
			{
				bDirectoryExists = Directory::isDir(sCurrentDirectory);
			}
			catch (const char* ex) { bDirectoryExists = FALSE; }

			if (bDirectoryExists == FALSE)
			{
				if (_mkdir(sCurrentDirectory.c_str()) != 0)
					throw("Could not make subdirectory.");
			}
		}
	}

	bool Directory::isFile(string szPath)
	{
		struct stat s;
		
		if (stat(szPath.c_str(), &s) == 0)
			return s.st_mode & S_IFREG;
		else
			throw("Can't stat file");
	}

	time_t Directory::getLastModifiedTime(string szPath)
	{
		struct stat s;

		if (stat(szPath.c_str(), &s) == 0)
			return s.st_mtime;
		else
			throw("Can't stat file");
	}

}
