#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    string bin,tri;
    cin>>bin>>tri;
    vector<string> vt;
    unordered_set<int> set;
    for(int i=1;i<bin.size();i++){
        string temp(bin);
        if(temp[i]-'0') temp[i] = '0';
        else temp[i] = '1';
        int res = 0;
        for(int j=0;j<bin.size();j++){
            res = res*2+temp[j]-'0';
        }
        set.insert(res);
    }
    for(int i=0;i<tri.size();i++){
        string temp(tri);
        string temp2(tri);
        if(temp[i]-'0' == 0){
            temp[i] = '1';
            vt.push_back(temp);
            temp2[i] = '2';
            vt.push_back(temp2);
        }else if(temp[i] - '1' == 0){
            temp[i] = '0';
            vt.push_back(temp);
            temp2[i] = '2';
            vt.push_back(temp2);
        }else{
            temp[i] = '0';
            vt.push_back(temp);
            temp2[i] = '1';
            vt.push_back(temp2);
        }
        int res1=0;
        int res2=0;
        for(int j=0;j<tri.size();j++){
            res1 = res1*3+temp[j]-'0';
            res2 = res2*3+temp2[j]-'0';
        }
        if(set.count(res1)){
            printf("%d\n",res1);
            break;
        }
        if(set.count(res2)){
            printf("%d\n",res2);
            break;
        }
    }

    return 0;
}