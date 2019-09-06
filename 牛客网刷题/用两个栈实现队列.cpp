#include <stack>
using namespace std;

class Solution
{
private:
	stack<int> s1;//push
	stack<int> s2;//pop

public:
	void push(int node)
	{
		s1.push(node);
	}
	int pop()
	{
		int tmp = s2.top();
		if(!s2.empty())
		{
			tmp = s2.top();
			s2.pop();
			return tmp;
		}
		else
		{
			while(!s1.empty())
			{
				tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
			if(!s2.empty())
			{
				tmp = s2.top();
			}
		}
		return tmp;
	}
};