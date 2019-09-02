#include <iostream>
#include <queue>
using namespace std;


class Solution
{
public:
	void Insert(int num)
	{
		if (maxp.empty() || num <= maxp.top())
		{
			minp.push(maxp.top());
			maxp.pop();
		}
		if(maxp.size()+1==minp.size())
		{
			maxp.push(minp.top());
			minp.pop();
		}
		if(maxp.size()==minp.size()+2)
		{
			minp.push(maxp.top());
			maxp.pop();
		}
	}

	double GetMedian() //��ȡ��ǰ��ȡ���ݵ���λ��
	{
		if (maxp.size() == minp.size())
			return (maxp.top() + minp.top()) / 2;
		else
			return maxp.top();
	}

private:
	priority_queue<int, vector<int>, less<int>> maxp; //�Ӵ�С������
	priority_queue<int, vector<int>, greater<int>> minp; //��С��������С��

};