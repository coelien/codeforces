#include<iostream>
using namespace std;

const int N = 20010;

int uniSet[N];

int find_root(int x){
    if(x!=uniSet[x]) uniSet[x] = find_root(uniSet[x]);
    return uniSet[x];
}

void union_both(int a, int b){
    int root_a = find_root(a);
    int root_b = find_root(b);
    if(root_a != root_b) uniSet[root_a] = root_b;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) uniSet[i] = i;
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        union_both(a,b);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int c,d;
        scanf("%d%d",&c,&d);
        if(find_root(c) == find_root(d)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}