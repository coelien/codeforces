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
vector<vector<int>> levelOrderBottom(TreeNode* root){
	queue<TreeNode*> que;
	stack<vector<int>>st;
	vector<vector<int>>res;
	if(root==nullptr) return res;
	que.push(root);
	while(!que.empty()){
		int size_q = que.size();
		vector<int> li;
		while(size_q--){
			TreeNode* cu = que.front();
			que.pop();
			li.push_back(cu->val);
			if(cu->left) que.push(cu->left);
			if(cu->right) que.push(cu->right);
		}
		st.push(std::move(li));
	}
	while(!st.empty()){
		res.push_back(std::move(st.top()));
		st.pop();
	}
	return res;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	auto res = levelOrderBottom(root);
	for(auto li : res){
		for(auto en: li){
			cout<<en<<" ";
		}
		cout<<endl;
	}
	return 0;
}	
