#include<iostream>
#include<unordered_set>

using namespace std;
const int INF = 0x3f3f3f3f;
int main(){
    int n,x0,y0;
    cin>>n>>x0>>y0;
    unordered_set<double> mySet;
    for(int i= 0; i<n ;++i){
        int x, y;
        cin>>x>>y;
        if(x==x0) mySet.insert(INF);
        else mySet.insert(1.0*(y-y0)/(x-x0));
    }
    cout<<mySet.size()<<endl;
}
