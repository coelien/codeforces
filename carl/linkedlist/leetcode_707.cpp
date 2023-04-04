#include<iostream>

using namespace std;

struct Node{
    int val=0;
    Node* next=nullptr;
    Node(int x):val(x),next(nullptr){}
    Node(int x, Node *ne):val(x),next(ne){}
    Node():val(0),next(nullptr){}
};

class MyLinkedList {
    Node * head, * tail;
    int length;
public:
    MyLinkedList() {
        head = new Node();
        tail = head;
        length= 0;
    }
    void printList(){
        Node* cu = head->next;
        while(cu){
            cout<<cu->val<<" ";
            cu = cu->next;
        }
        cout<<endl;
    }

    int getLen(){
        return length;
    }
    
    int get(int index) {
        int i=0;
        if(index <0 || index >= length) return -1;
        Node *cu = head->next;
        while(cu){
            if(i == index) return cu->val;
            cu = cu->next;
            i++;
        }
        // return -1;
    }
    
    void addAtHead(int val) {
        Node *nd = new Node(val,head->next);
        head->next = nd;
        if(length == 0) tail = nd;
        length++;
    }
    
    void addAtTail(int val) {
        if(length == 0){
            addAtHead(val);
            return;
        }
        Node * nd = new Node(val);
        tail->next = nd;
        tail = tail->next;
        length++;
    }
    
    void addAtIndex(int index, int val) {
        int i = 1;
        if(index>length) return;
        else if(index==length) addAtTail(val);
        else if(index<=0) addAtHead(val);
        else{
            Node * cu = head->next;
            while(cu){
                if(i == index){
                    Node * nd = new Node(val,cu->next);
                    cu->next = nd;
                    length++;
                    return;
                }
                cu = cu->next;
                i++;
            }
        }

    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>= length)return;
        Node * cu = head;
        int i = 0;
        while(cu->next){
            if(i == index){
                cu->next = cu->next->next;
                if(cu->next==nullptr) tail = cu;
                length--;
                return;
            }
            cu = cu->next;
            i++;
        }
    }
};

int main(){
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(7);
    linkedList->addAtHead(2);
    linkedList->addAtHead(1);//链表变为1-> 2-> 7
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    linkedList->addAtIndex(3,0);  //1 2 7 0 
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    linkedList->deleteAtIndex(2);  //现在链表是1 2 0
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    linkedList->addAtHead(6); //6 1 2 0
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    linkedList->addAtTail(4); //6 1 2 0 4
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    int a = linkedList->get(4);            //返回4
    cout<<a<<endl;
    linkedList->addAtHead(4); // 4 6 1 2 0 4
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    linkedList->addAtIndex(5,0);   //链表变为4 6 1 2 0 0 4
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    linkedList->addAtHead(6); // 6 4 6 1 2 0 0 4
    cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    // cout<<linkedList->getLen()<<endl;
    // linkedList->printList();
    return 0;
}