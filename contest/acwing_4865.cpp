#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<string> strs;
string fi;

void build_legal(vector<string>::iterator &ptr){
    if(ptr==strs.end()){
        printf("Error occurred\n");
        exit(0);
    }
    fi+=*ptr;
    if(*ptr == "pair"){
        fi+="<";
        build_legal(++ptr);
        fi+=",";
        build_legal(++ptr);
        fi+=">";
    }
}
int main(){
    int n;
    cin>>n;
    string s;
    while(cin>>s){
        strs.push_back(s);
    }
    auto st = strs.begin();
    build_legal(st);
    if(++st == strs.end())
        cout<<fi<<endl;
    else
        cout<<"Error occurred"<<endl;

}