#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		//¹þÏ£±í
		unordered_map<int, int> map;
		for (int i = 0; i < data.size(); i++)
			map[data[i]]++;
		vector<int> v;
		for (int i = 0; i < data.size(); i++)
			if (map[data[i]] == 1)
				v.push_back(data[i]);
		*num1 = v[0];
		*num2 = v[1];
	}
};


class Solution1
{
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		if (data.size() < 2)
			return;
		int result = 0;
		for (int i = 0;i < data.size();i++)
		{
			result ^= data[i];
		}
		unsigned int indexOf1 = FindFirstBitIs1(result);
		*num1 = *num2 = 0;
		for (int j = 0; j < data.size(); j++)
		{
			if (IsBit1(data[j], indexOf1))
				*num1 ^= data[j];
			else
				*num2 ^= data[j];
		}

	}

	unsigned int FindFirstBitIs1(int num)
	{
		int index = 0;
		while (((num & 1) == 0) && (index < 8 * sizeof(int)))
		{
			num = num >> 1;
			index++;
		}
		return index;
	}



	bool IsBit1(int num, unsigned int curBit)
	{
		num = num >> curBit;
		return (num & 1);
	}

};