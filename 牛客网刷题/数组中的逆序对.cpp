#include <vector>
using namespace std;

class Solution
{
	int mergeSort(vector<int> &data,vector<int> &v,int begin,int end)
	{
		if(begin==end)
		{
			v[begin] = data[begin];
			return 0;
		}
		int mid = (end - begin) / 2;
		int left = mergeSort(data, v, begin, begin + mid) % 1000000007;
		int right = mergeSort(data, v, begin + mid+1, end) % 1000000007;
		int i = begin + end;
		int j = end;
		int index = end;
		long long count = 0;
		while (i >= begin&&j >= begin+mid+1)
		{
			if(data[i]>data[j])
			{
				v[index--] = data[i--];
				count += j - begin - mid;//зЂвт
				if (count >= 1000000007)
					count %= 1000000007;
			}
			else
			{
				v[index--] = data[j--];
			}
			for(;i >=begin;i--)
			{
				v[index--] = data[i];
			}
			for(;j>=begin+mid+1;j--)
			{
				v[index--] = data[j];
			}
			for (int i = begin; i <= end; i++)
			{
				data[i] = v[i];
			}
			return (left + right + count) % 1000000007;

		}

	}

	int InversePairs(vector<int> data)
	{
		if (data.size() <= 0)
			return 0;
		vector<int> v;
		for (int i = 0; i < data.size(); i++)
		{
			v.push_back(data[i]);

		}
		long long count = mergeSort(data, v, 0, data.size()-1);
		return count;

	}
};