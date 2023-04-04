#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    string temp;
    istringstream in(s);
    // istream in2(in.rdbuf());
    vector<string> vec;
    while(in>>temp){
        string cur(temp);
        vec.push_back(cur);
    }
    string res;
    for(int i = vec.size()-1;i>=0;--i){
        res+=vec[i];
        if(i) res+=' ';
    }
    cout<<res<<endl;
    return 0;
}