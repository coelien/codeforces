#include<iostream>

using namespace std;

struct Node{
    int val=0;
    Node* next=nullptr;
    Node(int x):val(x),next(nullptr){}
    Node(int x, Node *ne):val(x),next(ne){}
    Node():val(0),next(nullptr){}
};

Node* head = new Node();

void insert(int x){
    Node *nd = new Node(x,head);
    head = nd;
}

void remove(Node* pre){
    pre->next =pre->next->next;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(x);
    }
    int val;
    cin>>val;
    while(head!=nullptr && head->val == val) head = head->next;
    if(head == nullptr) return 0;
    Node* pre = head;
    for(Node* cu = head->next;cu!=nullptr;cu=cu->next){
        if(cu->val == val){
            remove(pre);
        }
        else pre = cu;
    }

    for(Node* cu = head->next; cu!=nullptr;cu = cu->next){
        cout<<cu->val<<endl;
    }

    return 0;
}
