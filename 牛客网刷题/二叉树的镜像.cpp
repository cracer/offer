using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode*left, *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	void Mirror(TreeNode *pRoot)
	{
		TreeNode* tmpNode;
		if (pRoot == nullptr)
			return;
		if (pRoot->left || pRoot->right)
		{
			tmpNode = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = tmpNode;
			if (pRoot->left)
				Mirror(pRoot->left);
			if (pRoot->right)
				Mirror(pRoot->right);
		}
	}
};