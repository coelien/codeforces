#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010;

int h[N],e[2*N],ne[2*N],idx;
int color[N];

void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool dfs(int x, int cl){
    color[x] = cl;
    for(int i = h[x];i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j,3-cl)) return false;
        }else{
            if(color[j] == color[x])
                return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=0; i<m; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v);
        insert(v,u);
    }
    bool res = true;
    for(int i=1;i<=n;++i){
        if(!color[i]){
            res = dfs(i,1);
            if(res==false) break;
        }
    }
    if(res) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;

}
