//
// Created by sixwa on 2022/12/2.
//

#include <iostream>
using namespace std;
void solu_1205(){
    int n,m;
    cin>>n>>m;
    cout<<n*m-n-m;
}

void solu_1211(){
    int n;
    cin>>n;
    int x[60];
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    int left = 0,right = 0;
    for(int i=1;i<n;i++){
        if(abs(x[i])>abs(x[0]) && x[i]<0) left++;
        if(abs(x[i])<abs(x[0]) && x[i]>0) right++;
    }
    int res;
    if(x[0]>0 && left>0 || x[0]<0 && right>0) res = left+right+1;
    else res = 1;
    cout<<res;

}
void solu_1216(){
    int n;
    cin>>n;
    int res = n;
    while(n>=3){
        res += n/3;
        n = n/3+n%3;
    }
    cout<<res;
}
int main(){
//    solu_1205();
//    solu_1211();
    solu_1216();
}