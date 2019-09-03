#include <string>
using namespace std;

class Solution
{
public:
	string ReverseSentence(string str)
	{
		int len = str.size();
		if (len < 2) return str;
		string res = "", tmp = "";
		for(int i=0;i<len;i++)
		{
			if (str[i] == ' ')
			{
				res = " " + tmp + res;
				tmp = "";
			}
			else
			{
				tmp += str[i];
			}
		}
		if (tmp != "")
			res = tmp + res;
		return res;
	}
};