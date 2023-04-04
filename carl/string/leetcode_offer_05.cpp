#include<iostream>
#include<string>
using namespace std;

int main(){
    string s{"We are happy."};
    string res;
    for(int i = 0;i<s.size();i++){
        if(s[i] == ' ') res +="%20";
        else res += s[i];
    }
    cout<<res;
}