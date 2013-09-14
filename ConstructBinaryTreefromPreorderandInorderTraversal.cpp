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
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() == 0)
        	return NULL;
        for(int i=0;i<inorder.size();i++)
        {
        	if (inorder[i] == preorder[0])
        	{
        		TreeNode *p = new TreeNode(inorder[i]);
        		if(i==0)
        		{
        			p->left = NULL;
        		}
        		else
        		{
        			vector<int> LeftPre(&preorder[1],&preorder[i]);
        			vector<int> LeftIn(&inorder[0],&inorder[i-1]);
        			p->left = buildTree(LeftPre,LeftIn);
        		}
        		if(i== (preorder.size()-1) )
        		{
        			p->right = NULL;
        		}
        		else
        		{
        			vector<int> RightPre(&preorder[i+1],&preorder[preorder.size()]);
        			vector<int> RightIn(&inorder[i+1],&inorder[preorder.size()]);
        			p->right = buildTree(RightPre,RightIn);
        		}
        		return p;
        	}
        }
        return NULL;
    }

int main()
{
	vector<int> v1 = {1,2,3,4,5,6};
	vector<int> v2(&v1[6],&v1[6]);
	for (auto i:v2)
	{
		cout << i << " ";
	}
	cout << (v1.begin(),v1.begin()) << endl;
	cout << endl;
	return 0;
}