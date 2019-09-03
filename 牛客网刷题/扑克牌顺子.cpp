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
		int tmp = 15;//0-13֮�������ֵ
		for (int i = 0; i < numbers.size(); i++)
		{
			if (tmp == numbers[i]) return false;//�ظ�
			if (numbers[i] == 0)//����ӣ���������ѭ��
				continue;
			if (numbers[i] > max) max = numbers[i];
			if (numbers[i] < min) min = numbers[i];
			tmp = numbers[i];
			if (max - min >= 5) return false;//����5˵���������˳��
		}
		return true;
	}
};