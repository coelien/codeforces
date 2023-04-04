//
// Created by sixwa on 2023/2/16.
//

#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

typedef pair<int,int> PII;
vector<PII> pst,res;
const int N = 2e5+10;
int diff[N];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        memset(diff,0,sizeof diff);
        pst.clear();
        res.clear();
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            int st = 1;
            if(a) pst.push_back({max(st,i+1-a),i+1});
        }
        sort(pst.begin(),pst.end());
        if(pst.size()){
            int st=INT_MAX,ed=INT_MAX;
            for(PII cup: pst){
                int l = cup.first,r = cup.second;
                if(l<st) st = l;
                if(l>ed){
                    res.push_back({st,ed});
                    st = l;
                    ed = r;
                }
                else if(r>ed || ed == INT_MAX) ed = r;
            }
            res.push_back({st,ed});
        }
        for(PII cup:res){
            int l = cup.first,r = cup.second;
            diff[l] = 1;
            diff[r] = -1;
        }
        int cu = 0;
        for(int i=1;i<=n;i++){
//            printf("%d ",diff[i]);
            cu = cu+diff[i];
            printf("%d ",cu);
        }
        printf("\n");

    }
    return 0;

}
