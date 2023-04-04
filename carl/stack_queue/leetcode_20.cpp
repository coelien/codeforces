#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    char temp;
    for(int i=0;i<s.size();++i){
        switch (s[i])
        {
        case '(':
            st.push(s[i]);
            break;
        case '[':
            st.push(s[i]);
            break;
        case '{':
            st.push(s[i]);
            break;
        case ')':
            temp = st.top();
            if(temp == '(') st.pop();
            else {
                cout<<"false"<<endl;
                return -1;
            }
            break;
        case ']':
            temp = st.top();
            if(temp == '[') st.pop();
            else {
                cout<<"false"<<endl;
                return -1;
            }
            break;
        case '}':
            temp = st.top();
            if(temp == '{') st.pop();
            else {
                cout<<"false"<<endl;
                return -1;
            }
            break;
        default:
            break;
        }
    }
    if(!st.empty()){
        cout<<"false"<<endl;
        return -1;
    }
    else
        cout<<"true"<<endl;

    return 0;
}