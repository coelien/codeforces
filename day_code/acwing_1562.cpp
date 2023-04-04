#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1010;
const int M = 1000010;
int h[N], e[M], ne[M], idx;
int dist[N];
void insert(int a, int b){
    e[idx]=b;
    ne[idx] = h[a];
    h[a] = idx++;
}


int bfs(int x, int l){
    queue<int> que;
    que.push(x);
    dist[x] = 0;
    int cnt = 0;
    while(!que.empty()){
        int x = que.front();
        que.pop();
        for(int i = h[x];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]==-1){
                dist[j] = dist[x] + 1;
                ++cnt;
                if(dist[j]<l) que.push(j);
            }
        }
    }
    return cnt;
}
int main(){
    int n, l;
    cin>>n>>l;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;++j){
            int x;
            cin>>x;
            insert(x,i);
        }
    }

    int k;
    cin>>k;
    while(k--){
        int x;
        cin>>x;
        memset(dist,-1,sizeof dist);
        int ans = bfs(x,l);
        cout<<ans<<endl;
    }
}