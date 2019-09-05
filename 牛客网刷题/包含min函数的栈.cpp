#include <stack>
using namespace std;

class Solution
{
public:
	stack<int> s;
	stack<int> minStack;
	void push(int value)
	{
		s.push(value);
		if (minStack.size() == 0)
			minStack.push(value);
		if (value < minStack.top())
			minStack.push(value);
	}
	void pop()
	{
		if (s.top() == minStack.top())
		{
			s.pop();
			minStack.pop();
		}
		else
			s.pop();
	}

	int top()
	{
		return s.top();;
	}
	int min()
	{
		return minStack.top();
	}
};