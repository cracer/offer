using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left, *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	bool isSame(TreeNode* pRoot1,TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr)
			return pRoot2 == nullptr;
		if (pRoot2 == nullptr)
			return false;
		if (pRoot1->val == pRoot2->val)
			return isSame(pRoot1->left, pRoot2->right) && isSame(pRoot1->right, pRoot2->left);
		return false;
	}

	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		return isSame(pRoot->left, pRoot->right);
	}
};