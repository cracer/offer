using namespace std;

struct TreeLinkNode
{
	int val;
	struct TreeLinkNode *left, *right, *next;//next指向父节点的指针
	TreeLinkNode(int x): val(x),left(nullptr),right(nullptr),next(nullptr){}
};

class Solution
{
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;
		TreeLinkNode* res = nullptr;
		if(pNode->right!=nullptr)
		{
			TreeLinkNode* tmpRight = pNode->right;
			while (tmpRight->right!=nullptr)
			{
				tmpRight = tmpRight->left;
			}
			res = tmpRight;
		}
		else if(pNode->next!=nullptr)
		{
			TreeLinkNode* curNode = pNode;
			TreeLinkNode* parent = pNode->next;
			while (parent!=nullptr&&curNode==parent->right)
			{
				curNode = parent;
				parent = parent->next;
			}
			res = parent;
		}
		return res;
	}
};