#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}

};

class Solution
{
public:
	void InOrder(TreeNode* pRoot,vector<TreeNode*>& temp)
	{
		if (pRoot == nullptr)
			return;
		InOrder(pRoot->left, temp);
		temp.push_back(pRoot);
		InOrder(pRoot->right, temp);
	}

	TreeNode* KthNode(TreeNode* pRoot,int k)
	{
		if (pRoot == nullptr || k <= 0)
			return nullptr;
		vector<TreeNode*> temp;
		InOrder(pRoot, temp);
		if (k > temp.size())
			return nullptr;
		return temp[k - 1];
	}
};