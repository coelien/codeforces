//
// Created by sixwa on 2022/12/2.
//

#include <iostream>

using namespace std;
const int N = 1010;
int W[N];
int V[N];
int f[N][N];

void solu_01_pack() {
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &V[i], &W[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= v; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= V[i]) f[i][j] = max(f[i][j], f[i - 1][j - V[i]] + W[i]);
        }
    cout << f[n][v];
}

const int R = 110;
int fp[R];

void solu_1015() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        memset(fp, 0, sizeof fp);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int pea;
                scanf("%d", &pea);
                fp[j] = max(fp[j], fp[j - 1]) + pea;
            }
        }
        cout << fp[c] << endl;
    }
}

int sq[N];
int fsq[N];

void solu_895() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &sq[i]);
    sq[0] = -1e9 - 10;
    int max_len = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (sq[i] > sq[j])
                fsq[i] = max(fsq[j] + 1, fsq[i]);
        }
        if (fsq[i] > max_len) max_len = fsq[i];
    }
    cout << max_len;

}

const int mod = 1e8 + 7;
const int T = 55;
const int Y = 15;
int ft[T][T][Y][Y];
int tr[T][T];

int com_sum(int i, int j, int k, int c) {
    int sum = 0;
    for (int u = 0; u < c; u++)
        sum = (sum + ft[i][j][k][u]) % mod;
    return sum;
}

void solu_1212() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &tr[i][j]);
            tr[i][j]++;
        }

    ft[1][1][0][0] = 1;
    ft[1][1][1][tr[1][1]] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int p = 0; p <= k; p++) {
                for (int c = 0; c <= 13; c++) {
                    // 他选择取走
                    if (p > 0 && c == tr[i][j]) {
                        ft[i][j][p][c] = (ft[i][j][p][c] + com_sum(i - 1, j, p - 1, c)) % mod;
                        ft[i][j][p][c] = (ft[i][j][p][c] + com_sum(i, j - 1, p - 1, c)) % mod;
                    }
                    // 他不选择
                    ft[i][j][p][c] = ((ft[i][j][p][c] + ft[i - 1][j][p][c]) % mod + ft[i][j - 1][p][c]) % mod;
                }
            }
    cout << com_sum(n, m, k, 14);
}

int pf[N][N];

int get_mod(int a, int b){
    return (a%b+b)%b;
}
void solu_1214() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    // pf[i][j]: 前i个数，其总和模n的余数为j的方案总数
    pf[0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++){
            pf[i][j] = (pf[i][j]+pf[i-1][get_mod(j-a*i,n)])% mod;
            pf[i][j] = (pf[i][j]+pf[i-1][get_mod(j+b*i,n)])% mod;
        }
    cout<<pf[n-1][get_mod(s,n)];


}

int main() {
//    solu_01_pack();
//    solu_1015();
//    solu_895();
//    solu_1212();
    solu_1214();
    return 0;
}