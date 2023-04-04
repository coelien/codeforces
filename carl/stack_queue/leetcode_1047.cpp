#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main(){
    string s;
    cin>>s;

    deque<char> st;
    for(auto ch :s){
        if(st.empty() || st.back()!=ch) st.push_back(ch);
        else st.pop_back();
    }
    string res = "";
    copy(st.begin(),st.end(),back_inserter(res));
    // while(!st.empty()){
    //     res = st.top()+res;
    //     st.pop();
    // }
    cout<<res<<endl;
}