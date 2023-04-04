
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root){
	if(root == nullptr) return 0;
	return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}
int getHeight(TreeNode* root){
	if(root == nullptr) return 0;
	int le_h = getHeight(root->left);
	if(le_h == -1) return -1;
	int ri_h = getHeight(root->right);
	if(ri_h == -1) return -1;
	return abs(le_h-ri_h)>1? -1 : max(le_h,ri_h)+1;
	
}
bool isBalanced(TreeNode* root){
	return getHeight(root) == -1 ? false: true;
}
int main(int argc, char *argv[])
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	cout<<isBalanced(root)<<endl;
	return 0;
}
