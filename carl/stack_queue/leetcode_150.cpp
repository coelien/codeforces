#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

int main(){
    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    stack<int> st;
    for(string cu: tokens){
        if(cu == "+"){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(cu == "-"){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a-b);

        }
        else if(cu == "*"){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a*b);

        }
        else if(cu == "/"){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(a/b);

        }else{
            istringstream in(cu);
            int num;
            in>>num;
            st.push(num);
        }
    }
    cout<<st.top()<<endl;
    return 0;
}