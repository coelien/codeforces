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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
		if(root == nullptr) return res;
		st.push(root);
		while(!st.empty()){
			TreeNode* cu = st.top();
			if(cu){
				st.pop();
				st.push(cu);
				st.push(nullptr);
				if(cu->right){
					st.push(cu->right);
				}
				if(cu->left){
					st.push(cu->left);
				}
				
			}else{
				st.pop();
				res.push_back(st.top()->val);
				st.pop();
			}
		}
    return res;
}
int main(){
    TreeNode* root;
    vector<int> res = postorderTraversal(root);
    return 0;
}
