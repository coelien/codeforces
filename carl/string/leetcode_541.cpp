#include<iostream>
#include<string>
using namespace std;
void rev_helper(string &s, int i, int j){
    while(i<j){
        swap(s[i],s[j]);
        ++i;
        --j;
    }
}
int main(){
    string s{"abcdefg"};
    int k = 2;
    for(int i=0;i<s.size();i+=2*k){
        int dist = s.size()-i;
        if(dist<k){
            rev_helper(s,i,s.size()-1);
        }
        else{
            rev_helper(s,i,i+k-1);
        }
    }
    cout<<s;
}