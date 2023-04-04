#include<iostream>
using namespace std;
const int N = 100010;
int son[N][26];
int count[N];
int idx;
void init(){
    idx = 1;
}
void insert(const char *str){
    int cu = 0;
    for(int i=0;str[i];++i){
        int k = str[i]-'a';
        if(!son[cu][k]) son[cu][k] = idx++;
        cu = son[cu][k];
    }
    ++count[cu];
}
int query(const char *str){
    int cu = 0;
    for(int i=0;str[i];++i){
        int k = str[i]-'a';
        if(!son[cu][k]) return 0;
        cu = son[cu][k];
    }
    return count[cu];

}
int main(){
    int n;
    cin>>n;
    init();
    while(n--){
        char ch;
        char str[N];
        getchar();
        scanf("%c%s",&ch,str);
        if(ch=='I'){
            insert(str);
        }else if(ch =='Q'){
            printf("%d\n",query(str));
        }
        // for(int i = 0;str[i];++i){
        //     cout<<str[i]<<" ";
        // }
        // cout<<endl;
    }
    return 0;
}
