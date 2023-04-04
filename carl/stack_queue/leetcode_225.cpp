#include<iostream>
#include<queue>

using std::cin; using std::cout; using std::endl;
using std::queue;

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(x);
    }
    
    int pop() {
        int x;
        if(!q1.empty() && q2.empty()){
            while(!q1.empty() && q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            x = q1.front();
            q1.pop();
            return x;
        }else if(q1.empty() && !q2.empty()){
            while(!q2.empty() && q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            x = q2.front();
            q2.pop();
            return x;
        }else{
            cout<<"invlid"<<endl;
            return -1;
        }
    }
    
    int top() {
        int x;
        if(!q1.empty() && q2.empty()){
            while(!q1.empty() && q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            x = q1.front();
            q1.pop();
            q2.push(x);
            return x;
        }else if(q1.empty() && !q2.empty()){
            while(!q2.empty() && q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            x = q2.front();
            q2.pop();
            q1.push(x);
            return x;
        }else{
            cout<<"invlid"<<endl;
            return -1;
        }
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        else return false;
    }
};

int main(){
    MyStack* obj = new MyStack();
    obj->push(4);
    int param2 = obj->pop();
    int param3 = obj->top();
    bool param4 = obj->empty();
    cout<<param2<<" "<<param3<<" "<<param4<<endl;
}