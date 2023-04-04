#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth2(TreeNode* root){
	queue<TreeNode*> que;
	int res = 0;
	if(root==nullptr) return res;
	que.push(root);
	while(!que.empty()){
		++res;
		int size_que = que.size();
		int t = size_que;
		while(t--){
			TreeNode* cu = que.front();
			que.pop();
			if(cu->left) que.push(cu->left);
			if(cu->right) que.push(cu->right);
		}
	}

	return res;
}

int maxDepth(TreeNode* root){
	int le_dep=0,ri_dep = 0;
	if(root->left) le_dep	= maxDepth(root->left);
	if(root->right) ri_dep	= maxDepth(root->right);
	return max(le_dep, ri_dep)+1;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	cout<<maxDepth(root)<<endl;
	return 0;
}	
