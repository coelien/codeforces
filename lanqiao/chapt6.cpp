//
// Created by sixwa on 2023/2/20.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;
const int N = 210;
char maze[N][N];
int dist[N][N];
int directions[5] = {-1, 0, 1, 0, -1};
typedef pair<int, int> PII;

void flowersForArgi() {
    int t;
    cin >> t;
    while (t--) {
        queue<PII> que;
        memset(dist, -1, sizeof dist);
        int r, c;
        scanf("%d%d", &r, &c);
        int x0, y0;
        getchar();
        for (int i = 0; i < r; i++) {
            string line;
            getline(cin, line);
            for (int j = 0; j < c; j++) {
                char ch = line[j];
                maze[i][j] = ch;
                if (ch == 'S') x0 = i, y0 = j;
            }
        }

        que.push({x0, y0});
        dist[x0][y0] = 0;
        bool flag = false;
        while (!que.empty()) {
            PII pos = que.front();
            que.pop();
            if (maze[pos.first][pos.second] == 'E') {
                flag = true;
                cout << dist[pos.first][pos.second] << endl;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = directions[i] + pos.first;
                int ny = directions[i + 1] + pos.second;
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && dist[nx][ny] == -1 && maze[nx][ny] != '#') {
                    que.push({nx, ny});
                    dist[nx][ny] = dist[pos.first][pos.second] + 1;
                }
            }

        }
        if (!flag) cout << "oop!" << endl;

    }
}

const int M = 100010;
PII logs[M];
bool isHot[M];
int cnt[M];

void logStatics() {
    int n, d, k;
    scanf("%d%d%d", &n, &d, &k);
    for (int i = 0; i < n; i++) {
        int ts, id;
        scanf("%d%d", &ts, &id);
        logs[i] = {ts, id};
    }
    sort(logs, logs + n);
    for (int i = 0, j = 0; i < n; i++) {
        ++cnt[logs[i].second];
        while (logs[i].first - logs[j].first >= d)
            --cnt[logs[j++].second];
        if (cnt[logs[i].second] >= k) isHot[logs[i].second] = true;
    }

    for (int i = 0; i < M; i++)
        if (isHot[i])
            printf("%d\n", i);
}

const int Y = 30;
char g[Y][Y];
bool st[Y][Y];
int w, h;

int dfs_fill(PII start) {
    int x = start.first, y = start.second;
    st[x][y] = true;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i];
        int ny = y + directions[i + 1];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !st[nx][ny] && g[nx][ny] != '#') {
            res += dfs_fill(make_pair(nx, ny));
        }
    }
    return res + 1;
}

void redBlack() {
    while (cin >> w >> h && w != 0 && h != 0) {
        memset(st, 0, sizeof st);
        for (int i = 0; i < h; i++)
            scanf("%s", g[i]);
        PII start;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (g[i][j] == '@') start = {i, j};
        cout << dfs_fill(start) << endl;
    }

}

const int U = 10010;
int bot[U];
bool stb[U];

void switchBottle() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &bot[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!stb[i]) {
            cnt++;
            for (int j = i; !stb[j]; j = bot[j]) stb[j] = true;

        }
    }
    cout << n - cnt << endl;
}

int btree[M];
int stree[M];
const int EVIL = 1e9;

void levelSumBinTree() {
    memset(btree, EVIL, sizeof btree);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) scanf("%d", &btree[i]);
    for (int i = 1; i <= n; i++) stree[i] = stree[i - 1] + btree[i];
    int i, j;
    i = j = 1;
    int level_max = btree[1];
    int max_l = 1;
    int level = 1;
    while (i * 2 <= n) {
        level++;
        i = i * 2;
        if (j * 2 + 1 <= n) j = j * 2 + 1;
        else j = n;
        int sl = stree[j] - stree[i - 1];
        if (sl > level_max) {
            level_max = sl;
            max_l = level;
        }
    }
    cout<<max_l<<endl;

}
#include <deque>
const int K = 110;
char dung[K][K][K];
int dis[K][K][K];
struct point3D{
    int l,r,c;
};

void dungeonMaster(){
    int L,R,C;
    while(cin>>L && cin>>R && cin>>C && L!=0 && R!=0 && C!=0){
        memset(dis,-1,sizeof dis);

        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                scanf("%s",dung[i][j]);
            }
        }
        int l0,r0,c0;
        for(int i=0;i<L;i++)
            for(int j=0;j<R;j++)
                for(int k=0;k<C;k++)
                    if(dung[i][j][k]=='S')
                    {
                        l0 = i;
                        r0 = j;
                        c0 = k;
                    }
        deque<point3D> que;
        dis[l0][r0][c0] = 0;
        que.push_back({l0,r0,c0});
        bool flag = false;
        while(!que.empty()){
            auto [l,r,c] = que.front();
            que.pop_front();
            if(dung[l][r][c]=='E'){
                printf("Escaped in %d minute(s).\n",dis[l][r][c]);
                flag = true;
                break;
            }
            int direct_l[] = {1,0,0,-1,0,0};
            int direct_r[] = {0,1,0,0,-1,0};
            int direct_c[] = {0,0,1,0,0,-1};
            for(int i=0;i<6;i++){
                int nl = l+direct_l[i];
                int nr = r+direct_r[i];
                int nc = c+direct_c[i];
                if(nl>=0 && nl<L && nr>=0 && nr<R && nc>=0 && nc<C && dis[nl][nr][nc] == -1 && dung[nl][nr][nc]!='#'){
                    dis[nl][nr][nc] = dis[l][r][c] + 1;
                    que.push_back({nl,nr,nc});
                }
            }
        }
        if(!flag)
            printf("Trapped!\n");

    }
}
const int E = 1010;
char ocean[E][E];
bool visited[E][E];
bool isFlood[E][E];
int n;
bool flood(int x, int y){
    visited[x][y] = true;
    int flag = 0;
    if(!isFlood[x][y])
        flag = 1;
    for(int i=0;i<4;i++){
        int nx = x + directions[i];
        int ny = y + directions[i+1];
        if(nx>=0 && nx < n && ny>=0 && ny<n && ocean[nx][ny] == '#' && !visited[nx][ny]){
            if(!flood(nx,ny)) flag = 1;
        }
    }
    if(flag==1) return false;
    return true;
}
void islandFlood(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",ocean[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++) {
                int ni = i + directions[k];
                int nj = j + directions[k + 1];
                if(ni>=0 && ni < n && nj>=0 && nj<n)
                    if(ocean[ni][nj]=='.') {
                        isFlood[i][j]= true;
                        break;
                    }
            }
        }

    int cnt = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(ocean[i][j] == '#' && !visited[i][j]){
                if(flood(i,j)) cnt++;
            }
    cout<<cnt<<endl;
}

int he[M],e[M*2],ne[M*2],wei[M*2],idx;
int len[M];
void add(int a, int b, int w){
    e[idx] = b;
    wei[idx] = w;
    ne[idx] = he[a];
    he[a] = idx++;
}
void init(){
    memset(he,-1,sizeof he);
}
void dfs_road(int x){
    for(int i = he[x];i!=-1;i=ne[i]){
        int j = e[i];
        if(len[j]==-1) {
            len[j] = len[x] + wei[i];
            dfs_road(j);
        }
    }
}
void travelFee(){
    init();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int p,q,d;
        scanf("%d%d%d",&p,&q,&d);
        add(p,q,d);
        add(q,p,d);
    }
    memset(len,-1,sizeof len);
    len[1] = 0;
    dfs_road(1);
    int max_id = 1;
    int max_len = 0;
    for(int i=1;i<=n;i++)
        if(len[i]>max_len){
            max_len = len[i];
            max_id = i;
        }

    memset(len,-1,sizeof len);
    len[max_id] = 0;
    dfs_road(max_id);
    max_len = 0;
    for(int i=1;i<=n;i++)
        if(len[i]>max_len) max_len = len[i];
    int fea = 10*max_len+(max_len+1)*max_len/2;
    cout<<fea<<endl;


}

struct Node{
    int val;
    Node * next;
}nodes[M];
Node head{0, nullptr};
void addHead(int x){
    Node node{x, nullptr};
    node.next = head.next;
    head.next = &node;
}


int main() {
    // flowersForArgi();
    // logStatics();
    // redBlack();
    // switchBottle();
    // levelSumBinTree();
    // dungeonMaster();
    // islandFlood();
    // travelFee();
    return 0;
}