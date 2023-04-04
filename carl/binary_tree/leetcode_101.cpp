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



bool compare(TreeNode*left, TreeNode*right){
	if(!left && !right) return true;
	if(!left || !right) return false;
	if(left->val != right->val) return false;

	return compare(left->right, right->left) && compare(left->left, right->right);
}

bool isSymmetric(TreeNode* root){
	return compare(root->left,root->right);
}

int main(int argc, char *argv[])
{
	TreeNode* root = new TreeNode(1);
	root ->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	cout<<isSymmetric(root);

	return 0;
}
