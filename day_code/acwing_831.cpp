#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1000010;
int ne[N];
int main(){
    string s,p;
    int n;
    cin>>n>>p>>n>>s;
    // // O(m*n)
    // for(int i=0;i<=s.size()-p.size();i++){
    //     int j=0;
    //     for(;j<p.size();j++){
    //         if(s[i+j]!=p[j]) break;
    //     }
    //     if(j==p.size()) cout<<i<<" ";
    // }
    // cout<<s<<endl;
    int p_size = p.size();
    int s_size = s.size();
    s.push_back(' ');
    p.push_back(' ');
    copy(s.begin(),s.end(),s.begin()+1);
    copy(p.begin(),p.end(),p.begin()+1);
    // cout<<s<<endl;
    ne[1] = 0;
    for(int i=2,j = 0;i <= p_size; i++){
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i] = j;
    }
    // for(int i=1,j=0;i<=s_size;){
    //     if(s[i] == p[j+1] && j+1 < p_size) i++,j++;
    //     else if(s[i] == p[j+1] && j+1 == p_size){
    //         i++;
    //         j=ne[j+1];
    //         cout<<i-p_size-1<<" ";
    //     }
    //     else{
    //         if(j == 0) i++;
    //         else j = ne[j];  
    //     }   
    //     // cout<<i<<" "<<j<<endl;
    // }
    for(int i=1,j=0;i<=s_size;i++){
        while(j&&s[i]!=p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) ++j;
        if(j == p_size) {
            cout<<i-p_size<<" ";
            j = ne[j];
        }
    }
}