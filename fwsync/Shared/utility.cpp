#include "utility.h"

using namespace std;

namespace fwsync
{
	void strsplit(string str, vector<string> &tokens, char delim)
	{
		string buf;
		stringstream ss(str); // Insert the string into a stream

		while (getline(ss, buf, delim))
			tokens.push_back(buf);
	}


	void strsplit(string str, vector<string> &tokens, char delim, int iLimit)
	{
		string buf;
		stringstream ss(str); // Insert the string into a stream
		
		int iCount = 0;
		
		while (getline(ss, buf, delim))
		{
			tokens.push_back(buf);
			iCount++;

			if (iCount == iLimit - 1)
			{
				getline(ss, buf, '\0');
				tokens.push_back(buf);
				break;
			}

			
		}
	}
		
}
