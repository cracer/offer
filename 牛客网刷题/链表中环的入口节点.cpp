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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead)
			return nullptr;
		ListNode* pfast = pHead;
		ListNode* pslow = pHead;
		while (pfast&&pfast->next)
		{
			pslow = pslow->next;
			pfast = pfast->next->next;
			if(pfast==pslow)
			{
				pslow = pHead;
				while (pslow-pfast)
				{
					pslow = pslow->next;
					pfast = pfast->next;
				}
				return pfast;
			}
		}
		return nullptr;
	}
};