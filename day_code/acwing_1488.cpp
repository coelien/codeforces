#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N = 100010;
typedef pair<int, int> PII;
int h[N], e[3*N], ne[3*N],w[3*N],idx;
bool foundDist[N];
int minDist[N];
int n,m;

void insert(int a, int b, int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dijstra(){
	memset(minDist, 0x3f, sizeof minDist);
	minDist[0] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0,0});

	while(heap.size()){
		PII pa = heap.top();
		heap.pop();
		int p = pa.second;
		foundDist[p]=true;
		for(int i=h[p]; i!=-1; i=ne[i]){
			int j = e[i];
			if(!foundDist[j] && minDist[j]>minDist[p]+w[i]){
				minDist[j] = minDist[p]+w[i];
				heap.push({minDist[j],j});
			}
		}
	}

}

int main(){
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		insert(a,b,c);
		insert(b,a,c);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;++i){
		int x;
		scanf("%d",&x);
		insert(0,x,0);
		insert(x,0,0);
	}
	int q;
	scanf("%d",&q);
	dijstra();

	while(q--){
		int x;
		scanf("%d",&x);
		printf("%d\n",minDist[x]);
	}
	return 0;

}
