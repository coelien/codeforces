#include<iostream>

using namespace std;
int alg_s[30];
int alg_t[30];
int main(){
    string s,t;
    cin >>s>>t;
    for(int i=0;i<s.size();i++) ++alg_s[s[i]-'a'];
    for(int i=0;i<t.size();i++) ++alg_t[t[i]-'a'];
    for(int i=0;i<30;i++){
        if(alg_s[i]!=alg_t[i]){
            cout<< false;
            return 0;
        }
    }
    cout<< true;
}