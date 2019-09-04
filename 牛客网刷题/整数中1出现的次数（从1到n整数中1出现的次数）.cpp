
#include <complex>
using namespace std;

class Solution
{
public:
	int NumberOfDigitOne(int n)
	{
		if (n < 0) return 0;
		int i = 1;
		int high = n;
		int count = 0;
		while (high!=0)
		{
			high = n / pow(10, i);//表示当前的高位
			int tmp = n / pow(10, i - 1);
			int cur = tmp % 10;//表示第i为的值,从1开始
			int low = n - tmp * pow(10, i - 1);//表示当前位的低位
			if(cur < 1)
			{
				count += high * pow(10, i - 1);
			}
			else if(cur > 1)
			{
				count += (high + 1)*pow(10,i - 1);
			}
			else
			{
				count += high * pow(10, i - 1) + low + 1;
			}
			i++;
		}
		return count;
	}
};