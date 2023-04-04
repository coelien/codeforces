#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<set>
using namespace std;

const int N = 10;
int mat[N][N];
int n,m,k;
set<string> myset;
vector<int> path;
int direct[] = {-1,0,1,0,-1};
void dfs(int x, int y, int d){
    path.push_back(mat[x][y]);
    string pa = "";
    copy(path.begin(),path.end(),back_inserter(pa));
    if(d==k+1 && !myset.count(pa)){
        myset.insert(pa);
    }
    for(int i=0;i<4;++i){
        int nx = x+direct[i];
        int ny = y+direct[i+1];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(d<=k) dfs(nx,ny,d+1);
        }
    }
    path.pop_back();
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&mat[i][j]);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            dfs(i,j,1);
    cout<<myset.size()<<endl;
}