//
// Created by sixwa on 2022/11/22.
//
#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int nums[N];

int find_st(int x, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if (nums[l] != x) return -1;
    else return l;
}

int find_ed(int x, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (nums[mid] <= x) l = mid;
        else r = mid - 1;
    }
    if (nums[l] != x) return -1;
    else return l;
}

void solu_789() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    while (q--) {
        int k;
        scanf("%d", &k);
        int st = find_st(k, n);
        int ed = find_ed(k, n);
        printf("%d %d\n", st, ed);
    }
}

double root(double x) {
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    double l = 0;
    double r = ceil(x);
    double eps = 1e-8;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        if (mid * mid * mid <= x) l = mid;
        else r = mid;
    }
    if (neg) return -l;
    else return l;
}

void solu_790() {
    double n;
    cin >> n;
    double ans = root(n * 1.0);
    printf("%.6f", ans);
}

int prs[N];

void solu_795() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        prs[i] = prs[i - 1] + nums[i];
    }
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", prs[r] - prs[l - 1]);
    }

}

const int M = 1010;
int mat[M][M];
int s_mat[M][M];

void solu_796() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mat[i][j]);
            s_mat[i][j] = s_mat[i - 1][j] + s_mat[i][j - 1] - s_mat[i - 1][j - 1] + mat[i][j];
        }
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int res = s_mat[x2][y2] - s_mat[x2][y1 - 1] - s_mat[x1 - 1][y2] + s_mat[x1 - 1][y1 - 1];
        printf("%d\n", res);
    }
}

bool check_ok(int x, int n, int max) {
    for (int i = 1; i <= n; i++) {
//        x = 2*x - nums[i];
//        if(x<0) return false;
        if (nums[i] > x) {
            x = x - (nums[i] - x);
            if (x < 0) return false;
        } else {
            x = x + (x - nums[i]);
            if (x > max) return true;
        }
    }
    return true;
}

int bin_search(int l, int r, int n, int max) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check_ok(mid, n, max))
            r = mid;
        else l = mid + 1;
    }
    return l;
}

void solu_730() {
    int n;
    cin >> n;
    int min = N;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min = nums[i];
    }
    min = min / 2;
    int res = bin_search(min, max, n, max);
    cout << res;

}

#include<vector>

typedef pair<int, int> PII;
vector<PII> vec;

bool check_ok_1227(int x, int k) {
    int cnt = 0;
    for (auto ch: vec) {
        int h = ch.first;
        int w = ch.second;
        int hs = h / x;
        int ws = w / x;
        if (!hs || !ws) continue;
        cnt += hs * ws;
    }
    if (cnt >= k) return true;
    else return false;
}

int bin_search_1227(int l, int r, int k) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check_ok_1227(mid, k)) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solu_1227() {
    int n, k;
    cin >> n >> k;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int h, w;
        scanf("%d%d", &h, &w);
        if (min(h, w) > max) max = min(h, w);
        vec.push_back({h, w});
    }
    int res = bin_search_1227(1, max, k);
    cout << res;

}

const int P = 5010;
int s_area[P][P];

void solu_99() {
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        s_area[x + 1][y + 1] = s_area[x + 1][y + 1] + w;
    }
    for (int i = 1; i < P; i++)
        for (int j = 1; j < P; j++) {
            int add_new = 0;
            s_area[i][j] = s_area[i - 1][j] + s_area[i][j - 1] - s_area[i - 1][j - 1] + s_area[i][j];
        }

    double start = 0.5;
    double end = max(5001.5 - r, 0.5);
    int max_val = 0;
    for (double i = start; i <= end; i++)
        for (double j = start; j <= end; j++) {
            int x1 = ceil(i);
            int y1 = ceil(j);
            int board_x = min(i + r, 5001.5);
            int board_y = min(j + r, 5001.5);
            int x2 = floor(board_x);
            int y2 = floor(board_y);
            int cu_tar = s_area[x2][y2] - s_area[x2][y1 - 1] - s_area[x1 - 1][y2] + s_area[x1 - 1][y1 - 1];
            if (cu_tar > max_val) max_val = cu_tar;
        }
    cout << max_val;
}

void solu_1221_brute() {
    int n;
    cin >> n;
    for (int a = 0; a * a <= n; a++)
        for (int b = a; b * b + a * a <= n; b++)
            for (int c = b; c * c + b * b + a * a <= n; c++) {
                int d2 = n - a * a - b * b - c * c;
                int d = (int) sqrt(d2);
                if (d * d == d2 && d >= c) {
                    printf("%d %d %d %d", a, b, c, d);
                    exit(0);
                }
            }

}

const int Q = 5e6 + 10;
int men[Q];


void solu_1221_optim1() {
    int n;
    cin >> n;
    for (int c = 0; c * c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++) {
            int key = c * c + d * d;
            if (!men[key])
                men[key] = d;
        }
    for (int a = 0; a * a <= n; a++)
        for (int b = a; b * b + a * a <= n; b++) {
            int cd2 = n - a * a - b * b;
            if (!men[cd2]) continue;
            int d = men[cd2];
            int c = (int) sqrt(cd2 - d * d);
            printf("%d %d %d %d", a, b, c, d);
            return;
        }
}

#include <algorithm>

struct Sum {
    int s, c, d;

    bool operator<(const Sum &t) const {
        if (s != t.s) return s < t.s;
        if (c != t.c) return c < t.c;
        return d < t.d;
    }
} sum[Q];

int find_cd(int tar, int m) {
    int l = 0, r = m - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (sum[mid].s < tar)
            l = mid + 1;
        else
            r = mid;
    }
    if (sum[l].s != tar) return -1;
    return l;
}

void solu_1221_optim2() {
    int n;
    cin >> n;
    int m = 0;
    for (int c = 0; c * c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++)
            sum[m++] = {c * c + d * d, c, d};
    sort(sum, sum + m);
    for (int a = 0; a * a <= n; a++)
        for (int b = a; b * b + a * a <= n; b++) {
            int cd2 = n - a * a - b * b;
            int id = find_cd(cd2, m);
            if (id != -1) {
                printf("%d %d %d %d", a, b, sum[id].c, sum[id].d);
                return;
            }
        }
}

#include<unordered_map>

unordered_map<int, PII> mp;

void solu_1221_optim3() {
    int n;
    cin >> n;
    for (int c = 0; c * c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++) {
            int key = c * c + d * d;
            if (mp.count(key) == 0) mp[key] = {c, d};
        }
    for (int a = 0; a * a <= n; a++)
        for (int b = a; b * b + a * a <= n; b++) {
            int cd2 = n - a * a - b * b;
            if (mp.count(cd2) != 0) {
                printf("%d %d %d %d", a, b, mp[cd2].first, mp[cd2].second);
                return;
            }
        }
}
typedef long long LL;
const int Y = 1e5+10;
LL sk[Y];
int cnt[Y];
void solu_1230(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        sk[i] = sk[i-1]+x;
    }
    cnt[0] = 1;
    LL res = 0;
    for(int i=1;i<=n;i++){
        res += cnt[sk[i]%k];
        cnt[sk[i]%k]++;
    }
    printf("%ld",res);
}

int main() {
//    solu_789();
//    solu_790();
//    solu_795();
//    solu_796();
//    solu_730();
//    solu_1227();
//    solu_99();
//    solu_1221_brute();
//    solu_1221_optim1();
//    solu_1221_optim2();
//    solu_1221_optim3();
    solu_1230();
    return 0;
}
