#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* H = new ListNode();
ListNode* head = nullptr;
void insert(int x){
    ListNode *nd = new ListNode(x,H->next);
    H->next = nd;
}
int n;
int main(){
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    head = H->next;
    ListNode* cu = head;
    int length = 0;
    while(cu){
        ++length;
        cu = cu->next;
    }
    cin>>n;
    int index = length - n;
    int i=1;
    cu = H;
    while(index--){
        cu = cu->next;
    }
    cu->next = cu->next->next;
    for(ListNode* cu = H->next; cu!=nullptr;cu = cu->next){
        cout<<cu->val<<" ";
    }
    cout<<endl;
    return 0;
}