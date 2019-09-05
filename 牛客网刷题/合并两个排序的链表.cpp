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
	ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
	{
		if (pHead2 == nullptr) return pHead1;
		if (pHead1 == nullptr) return pHead2;
		ListNode* mergeHead = new ListNode(0);
		ListNode* current = mergeHead;
		while (pHead1!=nullptr&&pHead2!=nullptr)
		{
			if(pHead1->val < pHead2->val)
			{
				current->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				current->next = pHead2;
				pHead2 = pHead2->next;
			}
			current = current->next;
		}

		if (pHead1 == nullptr)
			current->next = pHead2;
		if (pHead2 == nullptr)
			current->next = pHead1;
		return mergeHead->next;
	}
};