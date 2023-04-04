//
// Created by sixwa on 2023/3/12.
//

#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b==0?a: gcd(b,a%b);
}
const int N = 100010;
int nums[N];
void acwing_1246(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i) scanf("%d",&nums[i]);
    int min_n=nums[0], max_n=nums[0],d=0;
    for(int i=0;i<n;i++){
        if(nums[i]<min_n) min_n = nums[i];
        if(nums[i]>max_n) max_n = nums[i];
    }
    for(int i=0;i<n;i++){
        int dec = nums[i]-min_n;
        if(dec<d) swap(dec,d);
        d = gcd(dec,d);
    }
    cout<<(max_n-min_n)/d+1<<endl;

}
int main(){
    acwing_1246();
}