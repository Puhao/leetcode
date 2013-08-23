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

int depth(TreeNode *root)
{
	if (root == NULL)
		return 0;
	queue<TreeNode *> q;
	int depth = 0;
	q.push(root);
	while (q.size())
	{
		int length = q.size();
		depth++;
		while(length--)
		{
			TreeNode *tmp = q.front();
			if ((tmp->left == NULL)&&(tmp->right == NULL))
				return depth;
			if (tmp->left != NULL)
				q.push(tmp->left);
			if (tmp->right != NULL)
				q.push(tmp->right);
			q.pop();
		}
	}
	return 0;
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
	cout << depth(a);
	return 0;
}

/*
class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
    	return 0;
	queue<TreeNode *> q;
	int depth = 0;
	q.push(root);
	while (q.size())
	{
		int length = q.size();
		depth++;
		while(length--)
		{
			TreeNode *tmp = q.front();
			if ((tmp->left == NULL)&&(tmp->right == NULL))
				return depth;
			if (tmp->left != NULL)
				q.push(tmp->left);
			if (tmp->right != NULL)
				q.push(tmp->right);
			q.pop();
		}
	}
	return 0;
    }
};
*/

