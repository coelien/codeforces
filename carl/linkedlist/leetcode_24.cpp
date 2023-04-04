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

int main(){
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    head = H->next;
    if(head == nullptr) return 0;
    ListNode* pre = H;
    ListNode* i = head;
    ListNode* j = head->next;
    if(j == nullptr) return 1;
    while(true){
        pre->next = j;
        i->next = j->next;
        j->next = i;
        
        
        j = i->next;
        if(j == nullptr) break;
        j = j->next;
        if(j==nullptr) break;
        pre = i;
        i = i->next;
        
    }
    
    for(ListNode* cu = H->next; cu!=nullptr;cu = cu->next){
        cout<<cu->val<<" ";
    }
    cout<<endl;
    return 0;
}

