#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 100010;
int h[N],e[N],ne[N],idx;

struct Edge{
    int st;
    int ed;
    Edge * ne;
    Edge(int st, int ed, Edge* ne):st(st),ed(ed),ne(ne){}
};
struct Node{
    int in_degree=0;
    int out_degree=0;
    Edge* edge=nullptr;
};

struct Graph{
    int n;
    vector<Node*> nodes;
    Graph(int n):n(n){
        for(int i=0;i<n;++i){
            nodes.push_back(new Node);
        }
    }
};

typedef pair<Node*, int> pii;

void insert(int a, int b, Graph &g){
    Edge* e = new Edge(a,b,g.nodes[a-1]->edge);
    g.nodes[a-1]->edge = e;
    ++g.nodes[a-1]->out_degree;
    ++g.nodes[b-1]->in_degree;
}
int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);

    for(int i=0;i<m;++i){
        int x, y;
        scanf("%d%d",&x,&y);
        insert(x,y,g);
    }

    queue<pii> que;
    for(int i=0;i<n;++i){
        if(g.nodes[i]->in_degree==0) que.push({g.nodes[i],i+1});
    }
    int count = 0;
    vector<int> res;
    while(!que.empty()){
        pii pa = que.front();
        que.pop();
        res.push_back(pa.second);
        ++count;
        Node* cu = pa.first;
        for(Edge* e = cu->edge; e!=nullptr; e = e->ne){
            if(--g.nodes[e->ed-1]->in_degree==0) que.push({g.nodes[e->ed-1],e->ed});
        }

    }
    if(count<n) cout<<-1<<endl;
    else{
        for(auto el:res) cout<<el<<" ";
    }


    return 0;
}