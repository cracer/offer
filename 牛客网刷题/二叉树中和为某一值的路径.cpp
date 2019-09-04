#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left, *right;
	TreeNode(int x) :val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	vector<vector<int> > res;
	vector<int> v;
	vector<vector<int> > FindPath(TreeNode* root,int expectNumber)
	{
		if (root == nullptr) return res;
		v.push_back(root->val);
		if (root->left == nullptr&&root->right == nullptr&&root->val == expectNumber)
			res.push_back(v);
		if (root->left != nullptr&&root->val < expectNumber)
			FindPath(root->left, expectNumber - root->val);
		if (root->right != nullptr&&root->val < expectNumber)
			FindPath(root->right, expectNumber - root->val);
		v.pop_back();
		return res;
	}

};