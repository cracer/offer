#include <vector>
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
	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		vector<TreeNode> vin;
		vector<int> vout;
		if (root == nullptr)
			return vout;
		vin.push_back(*root);
		while (!vin.empty())
		{
			TreeNode t1 = vin.front();
			vin.erase(vin.begin());
			if (t1.left != nullptr)
				vin.push_back(*t1.left);
			if (t1.right != nullptr)
				vin.push_back(*t1.right);
			vout.push_back(t1.val);
		}
		return vout;
	}
};