#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(root != nullptr) que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i=0; i<size; ++i){
            TreeNode* cu = que.front();
            que.pop();
            vec.push_back(cu->val);
            if(cu->left) {
                que.push(cu->left);
            }
            if(cu->right) {
                que.push(cu->right);
            }
        }
    }
    return res;
}

int main(){
    TreeNode* root;
    vector<vector<int>> res = levelOrder(root);
    return 0;
}