#include<iostream>
#include<set>
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
set<ListNode*> myset;
int main(){
    ListNode *headA, *headB;
    ListNode *cu = headA;
    while(cu){
        myset.insert(cu);
        cu = cu->next;
    }
    cu = headB;
    while(cu){
        if(myset.count(cu)){
            return 1;
        }
        cu = cu->next;
    }
    return 0;

}

