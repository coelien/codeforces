#include<iostream>
#include<cstring>

using namespace std;
const int N = 210;
int h[N],e[N*N],ne[N*N],idx;

void insert(int a, int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int match[N];
bool st[N];

bool find(int x){
	for(int i=h[x];i!=-1;i = ne[i]){
		int j = e[i];
		if(!st[j]){
			st[j] = true;
			if(!match[j]|| find(match[j])){
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	memset(h,-1,sizeof h);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int s;
		cin>>s;
		while(s--){
			int si;
			cin>>si;
			insert(i,si);
		}
	}

	int cnt = 0;
	for(int i=1;i<=n;++i){
		memset(st,0, sizeof st);
		if(find(i)) ++cnt;
	}
	cout<<cnt<<endl;

	return 0;
}
