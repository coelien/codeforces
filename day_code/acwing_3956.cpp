//
// Created by sixwa on 2023/2/15.
//
#include<iostream>

using namespace std;

const int N = 100010;
typedef long long LL;
int arr[N];
int s_arr[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) s_arr[i] = s_arr[i - 1] + arr[i];
    LL res = 0;
    if (s_arr[n] % 3)
        res = 0;
    else {
        int cnt = 0;
        for(int j = 2;j<n;j++){
            if(s_arr[j-1] == s_arr[n]/3) cnt++;
            if(s_arr[j] == s_arr[n]/3*2) res += cnt;
        }
    }
    printf("%lld\n", res);
    return 0;
}
