#include<iostream>
#include<unordered_set>

using namespace std;

const int N = 1010;

int primes[N];
bool st[N];

int cnt = 0;
void get_primes(int n){
    for(int i=2;i<=n;++i){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0; primes[j] <= n/i ; ++j){
            st[primes[j]*i] = true;
            if(i%primes[j]) break;
        }
    }
}
int main(){
    int t;
    cin >> t;
    get_primes(N-1);
    while(t--){
        int n,k;
        cin>>n>>k;
        int tc = 0;
        int i = 1;
        while(primes[i]<=n){
            int target = primes[i-1]+primes[i]+1;
            if(target<=n && !st[target]) ++tc;
            ++i;
        }
        if(tc>=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;

}
