#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool IsContinuous(vector<int> numbers)
	{
		if (numbers.empty()) return false;
		int max = 0;
		int min = 14;
		int tmp = 15;//0-13之外的任意值
		for (int i = 0; i < numbers.size(); i++)
		{
			if (tmp == numbers[i]) return false;//重复
			if (numbers[i] == 0)//是癞子，结束本次循环
				continue;
			if (numbers[i] > max) max = numbers[i];
			if (numbers[i] < min) min = numbers[i];
			tmp = numbers[i];
			if (max - min >= 5) return false;//大于5说明不能组成顺子
		}
		return true;
	}
};