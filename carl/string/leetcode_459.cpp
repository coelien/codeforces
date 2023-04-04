#include<string>
#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
string s;
const int N = 10010;
int ne[N];
int main(){
    cin>>s;
    ne[0] = -1;
    for(int i=1,j = -1;i<s.size();++i){
        while(j>=0 && s[i]!=s[j+1]) j = ne[j];
        if(s[i]==s[j+1]) ++j;
        ne[i] = j;
    }
    if(ne[s.size()-1]==-1 || s.size() % (s.size()-ne[s.size()-1]-1)) cout<<false;
    else cout<<true;
}