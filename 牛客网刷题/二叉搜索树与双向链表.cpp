using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left, *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr) return nullptr;
		if (pRootOfTree->left == nullptr&&pRootOfTree->right == nullptr)
			return pRootOfTree;
		TreeNode* leftNode = Convert(pRootOfTree->left);
		TreeNode* pNode = leftNode;
		while (pNode!=nullptr&&pNode->right!=nullptr)
		{
			pNode = pNode->right;
		}
		if(leftNode!=nullptr)
		{
			pNode->right = pRootOfTree;
			pRootOfTree->left = pNode;
		}
		TreeNode* rightNode = Convert(pRootOfTree->right);
		if(rightNode!=nullptr)
		{
			rightNode->left = pRootOfTree;
			pRootOfTree->right = rightNode;
		}
		return leftNode != nullptr ? leftNode : pRootOfTree;
	}
};