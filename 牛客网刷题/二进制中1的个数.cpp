class Solution
{
public:
	int NumberOf1(int n)
	{
		int cnt = 0;
		int bit = 1;
		while (bit!=0)
		{
			if (n&bit != 0)
				cnt++;
			bit = bit << 1;
		}
		return cnt;
	}
};