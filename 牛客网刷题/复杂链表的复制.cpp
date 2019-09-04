using namespace std;

struct RandomListNode
{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x):label(x),next(nullptr),random(nullptr){}
};

class Solution
{
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr) return nullptr;
		RandomListNode* tmpNode = pHead;
		while (tmpNode)
		{
			RandomListNode* newNode = new RandomListNode(tmpNode->label);
			newNode->next = tmpNode->next;
			tmpNode->next = newNode;
			tmpNode = tmpNode->next->next;
		}
		tmpNode = pHead;
		while (tmpNode)
		{
			RandomListNode* newNode = tmpNode->next;
			if (tmpNode->random != nullptr)
				tmpNode->random = tmpNode->random->next;
			tmpNode = tmpNode->next->next;//仅走原链表的节点
		}

		/*-----------拆分链表-----------*/
		tmpNode = pHead;
		RandomListNode* newHead = tmpNode->next;
		while (tmpNode)
		{
			RandomListNode* newHead = tmpNode->next;
			tmpNode->next = newHead->next;
			if (tmpNode->next != nullptr)
				newHead->next = tmpNode->next->next;
			tmpNode = tmpNode->next;
		}
		return newHead;
	}
};