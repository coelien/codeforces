#include<iostream>
#include<cstring>

const int N = 510;
const int INF = 0x3f3f3f3f;
int g[N][N];
bool st[N];
int dist[N];
using namespace std;

int prim(int n){
	int res = 0;
	for(int i=0;i<n;++i){
		int t = -1;
		for(int j=1;j<=n;++j){
			if(!st[j] && (t==-1||dist[t]>dist[j]))
				t = j;
		}
		if(i>0 && dist[t] == INF) return INF;
		if(i>0) res += dist[t];
		st[t] = true;
		for(int j=1;j<=n;++j){
			dist[j] = min(dist[j],g[t][j]);
		}
		
	}
	return res;
}

int main(){
	memset(g,0x3f, sizeof g);
	memset(dist,0x3f, sizeof dist);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v] = g[v][u] = min(g[u][v],w);
	}
	int res = prim(n);
	if(res == INF)
		cout<<"impossible\n"<<endl;
	else
		cout<<res<<endl;
}
