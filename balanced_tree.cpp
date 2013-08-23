/*
Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include <iostream>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool BalanceCheck(TreeNode *p, int &depth)
{
	if (p == NULL)
	{
		depth = 0;
		return true;
	}
	int LeftDepth = 0;
	int RightDepth = 0;
	bool result = true;
	result = BalanceCheck(p->left,LeftDepth) && BalanceCheck(p->right,RightDepth);
	int diff = LeftDepth - RightDepth;
	if ((diff != 0)&&(diff != 1)&&(diff != -1))
		result = false;
	depth = RightDepth > LeftDepth ? RightDepth + 1 : LeftDepth + 1;
	return result;
}

bool isBalanced(TreeNode *root)
{	
	int depth = 0;
	return BalanceCheck(root,depth);
}



int main()
{
	TreeNode *a = new TreeNode(4);
	TreeNode *b = new TreeNode(5);
	TreeNode *c = new TreeNode(5);
	TreeNode *d = new TreeNode(6);
	TreeNode *e = new TreeNode(6);
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	cout << isBalanced(a) << endl;
	cout << isBalanced(b) << endl;
	return 0;
}


