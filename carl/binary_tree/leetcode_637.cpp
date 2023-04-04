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

vector<double> averageOfLevels(TreeNode* root){
	queue<TreeNode*> que;
	vector<double>res;
	if(root==nullptr) return res;
	que.push(root);
	while(!que.empty()){
		int size_que = que.size();
		int t = size_que;
		double avg_level = 0;
		while(t--){
			TreeNode* cu = que.front();
			que.pop();
			avg_level+=cu->val;
			if(!t) res.push_back(avg_level/size_que);
			if(cu->left) que.push(cu->left);
			if(cu->right) que.push(cu->right);
		}
	}

	return res;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	auto res = averageOfLevels(root);
	for(auto li : res){
		cout<<li<<" ";
	}
	return 0;
}	
