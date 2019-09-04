#include <string>
using namespace std;

class Solution
{
public:
	int FirstNotRepeatingChar(string str)
	{
		int len = str.size();
		if (len == 0)
			return -1;
		int hasTable[256] = { 0 };
		for (int i = 0; i < len; i++)
		{
			hasTable[str[i]]++;
		}
		for (int i = 0; i < len; i++)
		{
			if (hasTable[str[i]] == 1)
				return i;
		}
		return -1;
	}
};