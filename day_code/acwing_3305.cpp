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
int f[N];
Process* ps[N];
queue<int> que;
bool inQue[N];

void insert(int a, int b, int c){
	Process * np = new Process(a,b,c,ps[a]);
	ps[a] = np;
	np = new Process(b,a,c,ps[b]);
	ps[b] = np;
}

void spfa(int n){
	while(!que.empty()){
		int cu = que.front();
		que.pop();
		inQue[cu] = false;
		for(auto i = ps[cu]; i!=nullptr; i = i->ne){
			if(max(f[i->a],f[i->b])+max(mature_time[i->a],mature_time[i->b])<f[i->c]){
				f[i->c] = max(f[i->a],f[i->b])+max(mature_time[i->a],mature_time[i->b]);
				if(!inQue[i->c]){
					que.push(i->c);
					inQue[i->c] = true;
				}
			}
		}
	}
}
int main(){
	int n,m,k,t;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=n;++i){
		scanf("%d",&mature_time[i]);
	}
	memset(f,0x3f,sizeof f);
	for(int i=0;i<m;++i){
		int x;
		scanf("%d",&x);
		f[x]=0;
		que.push(x);
	}
	for(int i=0;i<k;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		insert(a,b,c);
	}
	spfa(n);
	printf("%d\n",f[t]);

	return 0;
}
