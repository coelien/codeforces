#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
	int val;
	vector<Node*> children;
	Node(){}
	Node(int _val){
		val = _val;
	}
	Node(int _val, vector<Node*> _children){
		val = _val;
		children = _children;
	}
};

vector<vector<int>> levelOrder(Node* root){
	queue<Node*> que;
	vector<vector<int>> res;
	if(root == nullptr) return res;
	que.push(root);
	while(!que.empty()){
		int size_q = que.size();
		vector<int> li;
		while(size_q--){
			Node* cu = que.front();
			que.pop();
			li.push_back(cu->val);
			for(auto nd: cu->children){
				que.push(nd);
			}
		}
		res.push_back(li);
	}
	return res;
}

int main(){
	Node* root = new Node(1);
	Node* son1 = new Node(3);
	Node* son2 = new Node(2);
	Node* son3 = new Node(4);
	vector<Node*> ve{son1, son2,son3};
	root->children = ve;
	auto res = levelOrder(root);
	for(auto li : res){
		for(auto en: li){
			cout<<en<<" ";
		}
		cout<<endl;
	}
}

