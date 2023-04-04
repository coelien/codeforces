#include<iostream>
#include<stack>
using std::stack;
using std::cout;
using std::endl;
class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int x;
        if(!st2.empty()){
            x = st2.top();
            st2.pop();
            return x;
        }else{
            if(!st1.empty()){
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
                x = st2.top();
                st2.pop();
                return x;
            }else{
                cout<<"not valid!"<<endl;
                return -1;
            }
        }
    }
    
    int peek() {
        int x;
        if(!st2.empty()){
            x = st2.top();
            return x;
        }else{
            if(!st1.empty()){
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
                x = st2.top();
                return x;
            }else{
                cout<<"not valid!"<<endl;
                return -1;
            }
        }
    }
    
    bool empty() {
        if(st2.empty()&&st1.empty())return true;
        else return false;
    }
};
int main(){
    MyQueue *obj = new MyQueue();
    obj->push(3);
    int param2 = obj->pop();
    int param3 = obj->peek();
    bool param4 = obj->empty();
    cout<<param2<<" "<<param3<<" "<<param4<<endl;
}