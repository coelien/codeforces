#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;

		Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

		Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

		Node(int _val, Node* _left, Node* _right, Node* _next)
			: val(_val), left(_left), right(_right), next(_next) {}
};
void connect(Node* root){
	queue<Node*> que;
	que.push(root);
	if(root == nullptr) return;
	while(!que.empty()){
		int size_que = que.size();
		Node* pre = nullptr;
		while(size_que--){
			Node* cu = que.front();
			que.pop();
			if(pre!=nullptr) pre->next = cu;
			if(cu->left) que.push(cu->left);
			if(cu->right) que.push(cu->right);
			pre = cu;
		}
	}
}

int main(){
	Node* root = new Node(3);
	root->left = new Node(9);
	root->right = new Node(20);
	connect(root);

}
