#include<iostream>
#include<cstring>
#include<vector>
#include<queue>


using namespace std;

struct Process{
	int a,b,c;
	Process *ne=nullptr;
	Process(int a, int b, int c, Process* ne):a(a),b(b),c(c),ne(ne){}
};
const int N = 2010;
int mature_time[N];
int dist[N];
Process* ps[N];
bool foundMin[N];

void insert(int a, int b, int c){
	Process * np = new Process(a,b,c,ps[a]);
	ps[a] = np;
	np = new Process(b,a,c,ps[b]);
	ps[b] = np;
}
void dijstra(int n){	
	for (int i = 0; i < n; ++i) {
		int t = -1;
		for(int j=1;j<=n;++j){
			if(!foundMin[j] && (t==-1||dist[j]<dist[t]))
				t = j;
		}
		foundMin[t] = true;
		for(Process* k=ps[t]; k!=nullptr; k = k->ne){
			if(max(dist[k->a],dist[k->b])+max(mature_time[k->a],mature_time[k->b]) < dist[k->c])
				dist[k->c] = max(dist[k->a],dist[k->b])+max(mature_time[k->a],mature_time[k->b]);
		}
	}
}
int main(){
	int n,m,k,t;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=n;++i){
		scanf("%d",&mature_time[i]);
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=0;i<m;++i){
		int x;
		scanf("%d",&x);
		dist[x]=0;
	}
	for(int i=0;i<k;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		insert(a,b,c);
	}
	dijstra(n);
	printf("%d\n",dist[t]);

	return 0;
}
