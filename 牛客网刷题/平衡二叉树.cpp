using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left, *right;
	TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	bool IsBalance_Solution(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		int diff = left - right;
		if (diff > 1 || diff < -1)
			return false;
		return IsBalance_Solution(pRoot->left) && IsBalance_Solution(pRoot->right);
	}

	int TreeDepth(TreeNode* pRoot)//二叉树的深度
	{
		int depth = 0;
		if (pRoot == nullptr)
			return 0;
		TreeNode* tmp = pRoot;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		int res = left > right ? left : right;
		return res + 1;
	}
};