//
// Created by sixwa on 2023/2/17.
//
#include <iostream>
#include <unordered_set>
using namespace std;
const int P = 131;
const int N = 110;
typedef unsigned long long ULL;
int mails[N];
ULL h[N], p[N];
unordered_set<ULL> myset;

ULL getHash(int l, int r){
    return h[r]-h[l-1]*p[r-l+1];
}

bool check_condi(int n, int k){
    myset.clear();
    for(int r = k; r<=n;r++){
        int l = r-k+1;
        ULL hash_v = getHash(l,r);
        if(myset.count(hash_v))
            return false;
        myset.insert(hash_v);
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++) {
        char ch;
        scanf("%c",&ch);
        mails[i] = ch - 'A' +1;
    }
    p[0] = 1;
    for(int i=1;i<=n;i++) {
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + mails[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid = l+r>>1;
        if(check_condi(n,mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n",l);
    return 0;
}


