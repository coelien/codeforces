#include<iostream>

#include<unordered_set>

using namespace std;

int power(int x){
    int res = 0;
    while(x){
        res += (x%10)*(x%10);
        x/=10;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    unordered_set<int> log;
    while(n!=1){
        if(log.count(n)){
            cout<<"false"<<endl;
            return 0;
        }
        log.insert(n);
        n = power(n);
    }
    cout<<"true"<<endl;
    return 0;
}