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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* cu = st.top();
        st.pop();
        res.push_back(cu->val);
        if(cu->right) st.push(cu->right);
        if(cu->left) st.push(cu->left);
    }
    return res;
}
int main(){
    TreeNode* root;
    vector<int> res = preorderTraversal(root);
    return 0;
}