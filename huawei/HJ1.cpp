#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    int len = 0;
    while(cin>>s) len = s.size();
    cout<<len;
}