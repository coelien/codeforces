
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> binaryTreePaths(TreeNode* root){
	vector<string> res;
	if(root == nullptr) return res;
	if(root->left||root->right){
		if(root->left){
			auto temp = binaryTreePaths(root->left);
			for(auto& s:temp){
				s = std::to_string(root->val)+"->"+s;
				res.push_back(s);
			}
		}
		if(root->right){
			auto temp = binaryTreePaths(root->right);
			for(auto& s:temp){
				s = std::to_string(root->val)+"->"+s;
				res.push_back(s);
			}
		}
	}
	else{
		 res.push_back(std::to_string(root->val));
	}
	return res;
}
int main(int argc, char *argv[])
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	auto paths = binaryTreePaths(root);
	for(auto path: paths){
		cout<<path<<" ";
	}
	return 0;
}
