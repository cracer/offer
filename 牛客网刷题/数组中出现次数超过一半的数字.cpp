#include <vector>
using namespace std;

class Solution
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int len = numbers.size();
		if (len == 0) return 0;
		int* arr = new int[len];
		for (int i = 0; i < len; i++)
		{
			arr[i] = 0;
		}
		for(int i = 0;i < len; i++)
		{
			arr[numbers[i]]++;
			if (arr[numbers[i]] * 2 > len)
				return numbers[i];
		}
		return 0;
	}
};
