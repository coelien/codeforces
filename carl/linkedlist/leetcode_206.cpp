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
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    head = H->next;
    if(head == nullptr) return 0;
    ListNode* tail = head;
    while(tail->next) tail = tail->next;
    ListNode* cu = head;
    while(cu != tail){
        ListNode* temp = cu;
        cu = cu->next;
        temp->next = tail->next;
        tail->next = temp;
    }
    H->next = tail;
    for(ListNode* cu = H->next; cu!=nullptr;cu = cu->next){
        cout<<cu->val<<endl;
    }

}