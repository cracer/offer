#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.size();
		if (len <= 1)
			return s;
		vector<vector<int> > dp(len);
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (i == j)
					dp[i].push_back(1);
				else
					dp[i].push_back(0);
			}
		}
		int start = 0, max = 1;
		/*��Ϊ��Ҫ����dp[i+1][j-1]�����i�Ӵ�С��j��0��size-1��i��j-1��0*/
		for (int j = 0; j < len; j++)
		{
			for (int i = j - 1; i >= 0; i--)
			{
				if (s[i] == s[j])
				{
					if (j - i == 1)
						dp[i][j] = 2;
					else
					{
						if (dp[i + 1][j - 1]>0)
							dp[i][j] = dp[i + 1][j - 1] + 2;
						else
							dp[i][j] = 0;
					}
				}
				else
					dp[i][j] = 0;
				if (dp[i][j] > max)
				{
					max = dp[i][j];
					start = i;
				}
			}
		}
		return s.substr(start, max);
	}
};

