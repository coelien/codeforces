#include<iostream>
#include<vector>
#include<unordered_set>
#include<cstring>

using namespace std;

const int M = 160010;
const int N = 410;
int n,m;

struct Edge{
	int a, b;
	Edge * ne = nullptr;
	Edge(int a, int b, Edge* ne):a(a),b(b),ne(ne){};
};

Edge* rail[N];
Edge* road[N];

unordered_set<int> findSet;

int dist[N];
bool st[N];

void insert(int a, int b, Edge* rd[]){
	Edge* ed = new Edge(a,b,rd[a]);
	rd[a] = ed;
	ed = new Edge(b,a,rd[b]);
	rd[b] = ed;
}

void buildRoad(){
	for(int i=1;i<=n;++i){
		findSet.clear();
		findSet.insert(i);
		for(Edge* e=rail[i]; e!=nullptr; e=e->ne){
			findSet.insert(e->b);
		}
		for(int j=1;j<=n;++j){
			if(!findSet.count(j)) insert(i,j,road);
		}
	}
}

void dijstra(Edge* rd[]){
	memset(dist,0x3f,sizeof dist);
	memset(st, 0, sizeof st);
	dist[1] = 0;
	for(int i=0;i<n;++i){
		int t = -1;
		for(int j=1;j<=n;++j){
			if(!st[j] &&(t==-1||dist[t]>dist[j]))
				t = j;
		}
		st[t] = true;
		for(Edge* e = rd[t]; e!=nullptr; e=e->ne){
			if(dist[t]+1<dist[e->b])
				dist[e->b] = dist[t]+1;
		}
	}
}

int main(int argc, char *argv[])
{
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v,rail);
	}
	buildRoad();
	dijstra(rail);
	int rail = dist[n];
	dijstra(road);
	int road = dist[n];
	if(max(rail,road)==0x3f3f3f3f) cout<<-1;
	else cout<<max(rail, road)<<endl;
	return 0;
}
