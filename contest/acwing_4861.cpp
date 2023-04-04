//
// Created by sixwa on 2023/2/18.
//

#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        int w = n/10000 % 10;
        int q = n/1000 %10;
        int b = n/100 % 10;
        int s = n/10 % 10;
        int g = n % 10;
        int cnt = 0;
        if(w) cnt++;
        if(q) cnt++;
        if(b) cnt++;
        if(s) cnt++;
        if(g) cnt++;
        printf("%d\n",cnt);
        if(w) printf("%d ",w*10000);
        if(q) printf("%d ",q*1000);
        if(b) printf("%d ",b*100);
        if(s) printf("%d ",s*10);
        if(g) printf("%d ",g);
        printf("\n");
    }
    return 0;
}