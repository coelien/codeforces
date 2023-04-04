#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N = 10010;
string hay = "aabaaaababaababaa";
string needle = "bbbb";
int ne[N];
int main(){
    int s_size = hay.size();
    int p_size = needle.size();
    if(s_size<p_size){
        cout<<-1<<endl;
        return 0;
    }
    hay.push_back(' ');
    needle.push_back(' ');
    copy(hay.begin(),hay.end(),hay.begin()+1);
    copy(needle.begin(),needle.end(),needle.begin()+1);

    ne[1] = 0;
    for(int i=2, j=0;i<=p_size;++i){
        while(j && needle[i]!=needle[j+1]) j = ne[j];
        if(needle[i] == needle[j+1]) ++j;
        ne[i] = j;
    }

    for(int i=1,j=0 ;i<=s_size;++i){
        while(j && hay[i] != needle[j+1]) j = ne[j];
        if(hay[i] == needle[j+1]) ++j;
        if(j == p_size){
            cout<<i-p_size<<endl;
            j=ne[j];
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;

}