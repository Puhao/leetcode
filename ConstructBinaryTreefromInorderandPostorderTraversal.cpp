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

TreeNode *BuildeCore(int *in,int *post,int length)
{
	if (length <= 0)
		return NULL;
	for(int i=0;i<length;i++)
	{
		if ( *(in+i) == *(post+length-1))
		{
			TreeNode *p = new TreeNode(*(in+i));
			p->left = BuildeCore(in,post,i);
			p->right = BuildeCore(in+i+1,post+i,length-i-1);
			return p;
		}
	}
	return NULL;
}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *in = &inorder[0];
        int *post = &postorder[0];
        int length = postorder.size();
        return BuildeCore(in,post,length);
        
    }

int main()
{
	vector<int> v1 = {1,2,3,4,5,6};
	vector<int> v2(v1);
	buildTree(v1,v2);
	return 0;
}