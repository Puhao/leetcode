#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int Sum(TreeNode *p,int &max)
{
	if (p == NULL)
		return 0;
	int left = Sum(p->left,max);
	int right = Sum(p->right,max);
	int val = p->val;
	int tmpMax = val;
	if (left > 0)
		tmpMax += left;
	if (right > 0)
		tmpMax += right;
	if (tmpMax > max)
		max = tmpMax;
	int tmp = left > right ? left : right;
	if (tmp < 0)
		return val;
	else
		return tmp + val;
}

int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int max = INT_MIN;
	Sum(root,max);
	return max;
}

int main()
{
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	p1->left = p2;
	p1->right = p3;
	cout << maxPathSum(p1) << endl;
	return 0;
}