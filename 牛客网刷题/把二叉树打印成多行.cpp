#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int> > res;
		vector<int> v;
		queue<TreeNode*> q;
		if (!pRoot)
			return res;
		TreeNode* tmp = pRoot;
		TreeNode* pNode1, *pNode2;
		int value = 0;
		q.push(pRoot);
		while (!q.empty())
		{
			while (!q.empty()&&q.front()!=tmp)
			{
				pNode1 = q.front();
				value = pNode1->val;
				v.push_back(value);
				if (pNode1->left)
					q.push(pNode1->left);
				if (pNode1->right)
					q.push(pNode1->right);
				q.pop();
			}
			if(q.front()==tmp)
			{
				v.push_back(tmp->val);
				if(tmp->left)
				{
					q.push(tmp->left);
					pNode2 = tmp->left;
				}
				if (tmp->right)
				{
					q.push(tmp->right);
					pNode2 = tmp->right;
				}
				q.pop();
				tmp = pNode2;
			}
			res.push_back(v);
			v.clear();
		}
		return res;
	}
};