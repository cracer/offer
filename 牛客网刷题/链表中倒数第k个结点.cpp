struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution
{
public:
	ListNode* FindKthToTail(ListNode* pListNode,unsigned int k)
	{
		int count = 0;
		ListNode* tmp = pListNode;
		while (tmp!=nullptr)
		{
			++count;
			tmp = tmp->next;
		}
		count -= k;
		tmp = pListNode;
		if(count >= 0)
		{
			while (count--)
			{
				tmp = tmp->next;
			}
			return tmp;
		}
		else
		{
			return nullptr;
		}
	}
};