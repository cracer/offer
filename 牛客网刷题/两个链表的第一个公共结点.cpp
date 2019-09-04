using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution
{
public:
	int getListLength(ListNode* pHead)
	{
		int resLength = 0;
		ListNode* tmp = pHead;
		while (tmp!=nullptr)
		{
			tmp = tmp->next;
			resLength++;

		}
		return resLength;
	}

	ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode *pHead2)
	{
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;
		int L1 = getListLength(pHead1);
		int L2 = getListLength(pHead2);
		int diff = L1 - L2;

		ListNode* bList = pHead1;
		ListNode* sList = pHead2;

		
		if (diff < 0)
		{
			bList = pHead2;
			sList = pHead1;
			diff = L2 - L1;
		}

		for (int i = 0; i < diff; i++)
		{
			bList = bList->next;
		}
		while (bList!=nullptr&&sList!=nullptr&&bList!=sList)
		{
			bList = bList->next;
			sList = sList->next;
		}
		ListNode* sameNode = sList;
		return sameNode;
	}
};