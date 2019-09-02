using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x): val(x),next(nullptr){}
};

class Solution
{
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode* pre = new ListNode(0);
		pre->next = pHead;
		ListNode* cur = pHead;
		ListNode* head = pre;
		while (cur != nullptr && cur->next!=nullptr)
		{
			if(cur->val==cur->next->val)
			{
				int temp = cur->val;
				while (cur!=nullptr&&cur->val==temp)
				{
					cur = cur->next;
				}
				head->next = cur;
			}
			else
			{
				head = cur;
				cur = cur->next;
			}
		}
		return pre->next;
	}
};