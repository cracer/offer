#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution
{
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		vector<int> arrayList;
		stack<int> s;
		ListNode* tmp = head;
		while (tmp!=nullptr)
		{
			s.push(tmp->val);
			tmp = tmp->next;
		}
		while (!s.empty())
		{
			arrayList.push_back(s.top());
			s.pop();
		}
		return arrayList;
	}
};