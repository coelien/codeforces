//
// Created by sixwa on 2022/10/20.
//

#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//int cards[52];
//int f[52][52][52*52];
//int main() {
//    int n,a;
//    cin>>n>>a;
//    for(int i=1;i<=n;i++) scanf("%d",&cards[i]);
//    f[0][0][0]=1;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=i;j++){
//            for(int s=0;s<=j*a;s++){
//                f[i][j][s]= f[i-1][j][s];
//                if(s>cards[j]) f[i][j][s] = max(f[i][j][s],f[i-1][j-1][s-cards[j]]);
//            }
//        }
//    long long res = 0;
//    for(int j=1;j<=n;j++)
//        res += f[n][j][a*j];
//    cout<<res;
//    return 0;
//
//}
long long compute(char* str, int i){
    long long sum = 0;
    int j = strlen(str)-2;
//    long long tmp = str[t--]-'0';
//    int mul = 10;
    long long tmp = str[strlen(str)-j-2]-'0';
    for(;j>=0;j--)
        if(i>>j&1) {
            sum += tmp;
            tmp = str[strlen(str)-j-1]-'0';
        }
        else {
            tmp = tmp*10 + str[strlen(str)-j-1]-'0';
        }
    if(tmp) sum+=tmp;
    return sum;
}
int main(){
    char str[12];
    cin>>str;
    int len = strlen(str);
    long long sum = 0;
    for(int i=0;i<1<<(len-1);i++){
        sum+= compute(str,i);
    }
    cout<<sum;

}
