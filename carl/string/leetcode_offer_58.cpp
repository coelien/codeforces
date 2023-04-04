#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    string res = s.substr(k,s.size()-k)+s.substr(0,k);
    cout<<res<<endl;
}