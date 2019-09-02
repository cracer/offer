
#include <string>
using namespace std;

class Solution
{
	int StrToInt(string str)
	{
		int len = str.size();
		if (len <= 0)
			return 0;
		int symbol = 1;
		long long res = 0;
		if (str[0] == '-')
			symbol = -1;
		for (int i = (str[0]=='+'||str[0]=='-')?1:0; i < len; i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				res = (res << 1) + (res << 3) + (str[i] & 0xf);
			else
			{
				return 0;
			}
		}
		return res * symbol;
	}

};