#include<iostream>
#include<deque>
using namespace std;

struct Node{
    int val;
    Node * left, * right;
};

const int N = 40;
int mid[N];
int last[N];
//
// another way to build binary tree: using hashmap
// unordered_map<int, int> l; 存储每个结点的左结点
// unordered_map<int, int> r; 存储每个结点的右结点
// unordered_map<int, int> p; 存储中序遍历每个结点的下标
// int build(int al, int ar, int bl, int br, int d)
// {
//     int val = a[ar];
//     int k = p[val];
//     if(al<k) l[val] = build(al, al + k - 1 - bl, bl, k - 1, d + 1);
//     if(k<ar) r[val] = build(al + k - bl, ar - 1, k + 1, br, d + 1);
//     return val;
// }
// can be optimized by using hashmap. store every value's index in binary tree middle traverse 

int findRoot(int l, int r, int tar){
    for(int i=l;i<=r;i++){
        if(mid[i]==tar) return i;
    }
    throw runtime_error("must find sth");
}

void  buildBinTree(Node* & root,int ml, int mr, int ll, int lr){
    root = new Node{last[lr]};
    int idx = findRoot(ml,mr,last[lr]);
    int len_left = idx-ml, len_right=mr-idx;
    if(len_left) buildBinTree(root->left,ml,idx-1,ll,ll+len_left-1);
    if(len_right) buildBinTree(root->right,idx+1,mr,ll+len_left,lr-1);  
}
void bfsTree(Node * root){
    deque<Node*> que;
    que.push_back(root);
    while(!que.empty()){
        Node * cu = que.front();
        que.pop_front();
        printf("%d ",cu->val);
        if(cu->left) que.push_back(cu->left);
        if(cu->right) que.push_back(cu->right);
    }

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&last[i]);
    for(int i=0;i<n;i++) scanf("%d",&mid[i]);
    Node * root;
    buildBinTree(root,0, n-1, 0, n-1);
    bfsTree(root);
    return 0;
}