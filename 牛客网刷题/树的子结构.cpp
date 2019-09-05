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
	bool isSame(TreeNode* pRoot1,TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr) return true;
		if (pRoot1 == nullptr&&pRoot2 != nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);
	}

	bool isSubTree(TreeNode* pRoot1,TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr&&pRoot2 != nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return isSubTree(pRoot1->left, pRoot2) || isSubTree(pRoot1->right, pRoot2);
		return isSame(pRoot1, pRoot2) || isSubTree(pRoot1->left, pRoot2) || isSubTree(pRoot1->right, pRoot2);
	}

	bool HasSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		return isSubTree(pRoot1, pRoot2);
	}
};