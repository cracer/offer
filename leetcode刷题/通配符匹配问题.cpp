#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool isMatch(string s, string p) 
	{
		int sLen = s.length();
		int pLen = p.length();
		vector<vector<bool> > dp(sLen + 1,vector<bool>(pLen+1,false));//初始化

		dp[0][0] = true;
		for(int j = 1;j <= pLen;j++)
		{
			if (p.at(j-1) == '*')
				dp[0][j] = true;
			else
				break;
		}

		for (int i = 1; i <= sLen; i++)
		{
			for (int j = 1; j <= pLen; j++)
			{
				if (p.at(j - 1) == '?' || s.at(i - 1) == p.at(j - 1))
					dp[i][j] = dp[i - 1][j - 1];
				else if (p.at(i - 1) == '*')
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				else
					dp[i][j] = false;
			}
		}
		return dp[sLen][pLen];
	}
};

class Solution2 {
public:
	bool isMatch(string s, string p) {

		int i = 0;
		int j = 0;
		int star = -1;
		int k = 0; // 记录最后一次匹配的位置 +1

		while (i < s.length()) 
		{
			if (s[i] == p[j] || p[j] == '?') 
			{
				++i; 
				++j;
				continue;
			}

			if (p[j] == '*') 
			{
				star = j++;
				k = i;
				continue;
			}

			// 如果失配了，回溯到 k + 1，即让 * 再多吞噬一个字符。
			if (star != -1) 
			{
				i = ++k;
				j = star + 1;
				continue;
			}
			return false;
		}

		while (j < p.length() && p[j] == '*') 
			++j;

		return j == p.length();
	}
};