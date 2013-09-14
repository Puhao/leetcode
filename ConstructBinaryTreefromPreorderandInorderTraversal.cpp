#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *BuildeCore(int *pre,int *in,int length)
{
	if(length <= 0)
		return NULL;
	for(int i=0;i<length;i++)
	{
		if (*(in+i) == *pre)
		{
			TreeNode *p = new TreeNode(*(in+i));
			p->left = BuildeCore(pre+1,in,i);
			p->right = BuildeCore(pre+i+1,in+i+1,length -i -1);
			return p;
		}
	}
	return NULL;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() != inorder.size())
        	return NULL;
        int *pre = &preorder[0];
        int *in = &inorder[0];
        int length = preorder.size();
        TreeNode *p = BuildeCore(pre,in,length);
        return p;
    }

int main()
{
	vector<int> v1 = {1,2,3,4,5,6};
	vector<int> v2(v1);
	buildTree(v1,v2);
	return 0;
}