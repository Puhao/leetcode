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

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if ((p == NULL) && (q == NULL))
		return true;
	if ((p == NULL) && (q != NULL))
		return false;
	if ((p != NULL) && (q == NULL))
		return false;
	if (p->val == q->val)
		return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	else
		return false;
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
	cout << IsSameTree(a,b);
	cout << IsSameTree(d,e);
	return 0;
}


