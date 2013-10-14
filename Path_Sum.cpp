#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (root == NULL)
		return false;
	if (root->left == NULL && root->right == NULL)
	{
		if (root->val == sum)
			return true;
		else
			return false;
	}
	bool ret = false;
	ret = hasPathSum(root->left,sum - root->val);
	if (ret)
		return true;
	else
		ret = hasPathSum(root->right, sum - root->val);
	return ret;
}

int main()
{
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	p1->left = p2;
	p2->right = p3;
	cout << hasPathSum(p1,1) << endl;
	return 0;
}