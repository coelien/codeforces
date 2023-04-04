#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<char> s{'h','e','l','l','o'};
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        swap(s[i],s[j]);
        ++i;
        --j;
    }
    for(auto ch:s){
        cout<<ch<<" ";
    }
    return 0;
}