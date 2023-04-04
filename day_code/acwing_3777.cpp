#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N = 210;
char blocks[N];
char cpy[N];
vector<int> ops;

bool canTrans(int n, char ch, char tch){
    memcpy(cpy,blocks,sizeof blocks);
    ops.clear();
    for(int i=0;i<n-1;i++){
        if(cpy[i]!=ch) {
            cpy[i] = ch;
            if(cpy[i+1] == ch) cpy[i+1] = tch;
            else cpy[i+1] = ch;
            ops.push_back(i+1);
        }
    }
    if(cpy[n-1] == ch) return true;
    else return false;
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        scanf("%s",blocks);
        if(canTrans(n,'B','W') || canTrans(n,'W','B')){
            printf("%d\n",ops.size());
            if(ops.size()) {
                for(int e:ops) printf("%d ",e);
                printf("\n");
            }
        }
        else printf("-1\n");

    }
}