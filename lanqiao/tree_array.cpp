//
// Created by sixwa on 2023/2/14.
//
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 10010;
const int M = 1000010;
int stars[N], tri[M];

int lowbit(int x) {
    return x & (-x);
}

void add_v(int x, int v) {
    for (int i = x; i <= M; i += lowbit(i)) tri[i] += v;
}

int sum_x(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tri[i];
    return res;
}

void countStars() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        // tree array ask x>=1
        x += 1;
        int cnt = sum_x(x);
        stars[cnt]++;
        add_v(x, 1);
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", stars[i]);
}

void sumDynamicRegions() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add_v(i, x);
    }
    int k, a, b;
    while (m--) {
        scanf("%d%d%d", &k, &a, &b);
        if (k == 0)
            printf("%d\n", sum_x(b) - sum_x(a - 1));
        else
            add_v(a, b);
    }

}

struct Node {
    int l, r;
    int maxNum;
} reT[4 * N];
int w[N];

void pushup(int x) {
    int l = x << 1;
    int r = x << 1 | 1;
//    reT[x].maxNum = max(reT[l].maxNum,reT[r].maxNum);
    reT[x].maxNum = reT[l].maxNum + reT[r].maxNum;
}

void build(int x, int l, int r) {
    if (l == r) {
        Node d = {l, r, w[r]};
        reT[x] = d;
        return;
    }
    Node d = {l, r};
    int mid = l + r >> 1;
    int ls = x << 1;
    int rs = x << 1 | 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    reT[x] = d;
    pushup(x);
}

void modify(int x, int num, int v) {
    int l = reT[x].l;
    int r = reT[x].r;
    if (l == r) {
        if (l != num) printf("sth wrong!");
//        reT[x].maxNum=v;
        reT[x].maxNum += v;
        return;
    }
    int mid = l + r >> 1;
    if (num <= mid) modify(x << 1, num, v);
    else modify(x << 1 | 1, num, v);
    pushup(x);
}

int query(int x, int ql, int qr) {
    int l = reT[x].l;
    int r = reT[x].r;
    if (l >= ql && r <= qr) return reT[x].maxNum;
    int mid = l + r >> 1;
//    int maxNum = INT_MIN;
//    if(ql<=mid) maxNum = query(x<<1,ql,qr);
//    if(qr>mid) maxNum = max(maxNum, query(x<<1|1,ql,qr));
    int maxNum = 0;
    if (ql <= mid) maxNum = query(x << 1, ql, qr);
    if (qr > mid) maxNum += query(x << 1 | 1, ql, qr);

    return maxNum;
}

void maxRegions() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    int x, y;
    while (m--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1, x, y));
    }
}

void sumDynamicRegionsII() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    build(1, 1, n);
    int k, a, b;
    while (m--) {
        scanf("%d%d%d", &k, &a, &b);
        if (k == 0)
            printf("%d\n", query(1, a, b));
        else
            modify(1, a, b);
    }
}

typedef long long LL;
int hei[N];
int times[N];
int temp[N];
int mapId[N];
int tmpMap[N];

void merge(int l1, int r1, int l2, int r2) {
    int i = l1, j = l2, k = l1;
    memcpy(tmpMap, mapId, sizeof mapId);
    while (i <= r1 && j <= r2) {
        if (hei[i] <= hei[j]) {
            mapId[k] = tmpMap[i];
            temp[k++] = hei[i++];

        } else {
            // hei[i] ~ hei[r1] > hei[j]
            int m = r1 - i + 1;
            for (int p = 0; p < m; p++) {
                times[tmpMap[i + p]]++;
                times[tmpMap[j]]++;
            }
            mapId[k] = tmpMap[j];
            temp[k++] = hei[j++];
        }
    }
    while (i <= r1) {
        mapId[k] = tmpMap[i];
        temp[k++] = hei[i++];
    }
    while (j <= r2) {
        mapId[k] = tmpMap[j];
        temp[k++] = hei[j++];
    }
    for (int k = l1; k <= r2; k++) hei[k] = temp[k];
}

void mergesort(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, mid, mid + 1, r);
}

void kidsQueue() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &hei[i]);
    for (int i = 1; i <= n; i++) mapId[i] = i;
    mergesort(1, n);
    LL res = 0;
    for (int i = 1; i <= n; i++) res += (LL) times[i] * (1 + times[i]) / 2;
    printf("%lld\n", res);

}

void kidsQueueII() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &hei[i]);
        hei[i]++;
    }
    for (int i = 1; i <= n; i++) {
        times[i] = sum_x(M - 1) - sum_x(hei[i]);
        add_v(hei[i], 1);
    }
    memset(tri, 0, sizeof tri);
    for (int i = n; i >= 1; i--) {
        times[i] += sum_x(hei[i] - 1);
        add_v(hei[i], 1);
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) res += (LL) times[i] * (1 + times[i]) / 2;
    printf("%lld\n", res);

}

struct Seq {
    int x, y1, y2;
    int k;

    bool operator<(const Seq &seq) const {
        return x < seq.x;
    }
} seqs[2 * N];

struct Reg {
    int l, r;
    int cnt;
    int len;
} regs[4 * N];

void pushup_reg(int x) {
    if (regs[x].cnt > 0) regs[x].len = regs[x].r - regs[x].l + 1;
    else if (regs[x].l == regs[x].r) regs[x].len = 0;
    else regs[x].len = regs[x << 1].len + regs[x << 1 | 1].len;
}

void build_reg(int x, int l, int r) {
    regs[x] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build_reg(x << 1, l, mid);
    build_reg(x << 1 | 1, mid + 1, r);
}

void modify_reg(int x, int l, int r, int v) {
    if (regs[x].l >= l && regs[x].r <= r) {
        regs[x].cnt += v;
        pushup_reg(x);
        return;
    }
    int mid = regs[x].l + regs[x].r >> 1;
    if (l <= mid) modify_reg(x << 1, l, r, v);
    if (r > mid) modify_reg(x << 1 | 1, l, r, v);
    pushup_reg(x);
}

int query_reg(int x) {
    return regs[x].len;
}

void paintArea() {
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        seqs[m++] = {x1, y1, y2, 1};
        seqs[m++] = {x2, y1, y2, -1};
    }
    sort(seqs, seqs + m);
    build_reg(1, 0, N);
    int area = 0;
    for (int i = 0; i < m; i++) {
        if (i) area += (seqs[i].x - seqs[i - 1].x) * query_reg(1);
        modify_reg(1, seqs[i].y1, seqs[i].y2 - 1, seqs[i].k);
    }
    printf("%d\n", area);
}

const int R = 1000010;
int ships[2 * R];
int b[2 * R], bn[2 * R];
int sa[2 * R];
int A, B, C;

struct Attack {
    int la, ra;
    int lb, rb;
    int lc, rc;
    int h;
} atks[R];

int getShip(int i, int j, int k) {
    return (i * B + j) * C + k;
}

bool checkExplode(int m) {
    memcpy(bn, b, sizeof b);
    for (int i = 0; i < m; i++) {
        int la = atks[i].la, ra = atks[i].ra;
        int lb = atks[i].lb, rb = atks[i].rb;
        int lc = atks[i].lc, rc = atks[i].rc;
        int h = atks[i].h;
        bn[getShip(la, lb, lc)] -= h;
        bn[getShip(la, rb + 1, lc)] += h;
        bn[getShip(ra + 1, lb, lc)] += h;
        bn[getShip(la, lb, rc + 1)] += h;
        bn[getShip(ra + 1, rb + 1, lc)] -= h;
        bn[getShip(ra + 1, lb, rc + 1)] -= h;
        bn[getShip(la, rb + 1, rc + 1)] -= h;
        bn[getShip(ra + 1, rb + 1, rc + 1)] += h;
    }

    memset(sa, 0, sizeof sa);

    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k <= C; k++) {
                sa[getShip(i, j, k)] = bn[getShip(i, j, k)]
                                       + sa[getShip(i - 1, j, k)]
                                       + sa[getShip(i, j - 1, k)]
                                       + sa[getShip(i, j, k - 1)]
                                       - sa[getShip(i - 1, j - 1, k)]
                                       - sa[getShip(i - 1, j, k - 1)]
                                       - sa[getShip(i, j - 1, k - 1)]
                                       + sa[getShip(i - 1, j - 1, k - 1)];
                if (sa[getShip(i, j, k)] < 0) return true;
            }
    return false;
}

void threeBodyAttack() {
    int m;
    scanf("%d%d%d%d", &A, &B, &C, &m);
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k <= C; k++)
                scanf("%d", &ships[getShip(i, j, k)]);

    for (int i = 0; i < m; i++) {
        int la, ra, lb, rb, lc, rc, h;
        scanf("%d%d%d%d%d%d%d", &la, &ra, &lb, &rb, &lc, &rc, &h);
        atks[i] = {la, ra, lb, rb, lc, rc, h};
    }

    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k <= C; k++)
                b[getShip(i, j, k)] = ships[getShip(i, j, k)]
                                      - ships[getShip(i - 1, j, k)]
                                      - ships[getShip(i, j - 1, k)]
                                      - ships[getShip(i, j, k - 1)]
                                      + ships[getShip(i - 1, j - 1, k)]
                                      + ships[getShip(i - 1, j, k - 1)]
                                      + ships[getShip(i, j - 1, k - 1)]
                                      - ships[getShip(i - 1, j - 1, k - 1)];
    int l = 1, r = m;
    while (l < r) {
        int mid = l + r >> 1;
        if (checkExplode(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
}

int dis(int x, int y) {
    if (x == -1 && y == 0)
        return 1;

    if (y >= x && y > -x) return dis(x - 1, y) + 1;
    if (y < x && y >= -x) return dis(x, y + 1) + 1;
    if (y <= -x && y > x + 1) return dis(x, y - 1) + 1;
    if (y <= x + 1 && y < -x) return dis(x + 1, y) + 1;
}

void spiralLen() {
    int x, y;
    cin >> x >> y;
    cout << dis(x, y) << endl;
}

void spiralLenII() {
    int x, y;
    cin >> x >> y;
    LL dis = 0;
    if (y >= x && y > -x) {
        dis = (LL) (2 * y) * (2 * y - 1) + x + y;
    } else if (y < x && y >= -x) {
        dis = (LL) (2 * x) * (2 * x) + x - y;
    } else if (y <= -x && y > x + 1) {
        dis = (LL) ((-x) * 2 - 1) * ((-x) * 2 - 1) + y - (x + 1);
    } else if (y <= x + 1 && y < -x) {
        dis = (LL) (-y) * 2 * ((-y) * 2 + 1) + (-y) - x;
    }
    cout << dis << endl;
}

void spiralLenIII() {
    int x, y;
    cin >> x >> y;
    int k = max(abs(x), abs(y));
    if (y >= x) cout << 4 * k * k - abs(x - k) - abs(y - k);
    else cout << 4 * k * k + abs(x - k) + abs(y - k);
}

const int Y = 1010;
int s_int[Y];
int d_int[Y];

void diffSum() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &s_int[i]);

    for (int i = 1; i <= n; i++) d_int[i] = s_int[i] - s_int[i - 1];

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        d_int[l] += c;
        d_int[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) s_int[i] = s_int[i - 1] + d_int[i];
    for (int i = 1; i <= n; i++) printf("%d ", s_int[i]);

}

int d_arr[Y][Y], s_array[Y][Y];

void diffArr() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &s_array[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d_arr[i][j] = s_array[i][j] - s_array[i - 1][j] - s_array[i][j - 1] + s_array[i - 1][j - 1];

    while (q--) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        d_arr[x1][y1] += c;
        d_arr[x1][y2 + 1] -= c;
        d_arr[x2 + 1][y1] -= c;
        d_arr[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s_array[i][j] = d_arr[i][j] + s_array[i - 1][j] + s_array[i][j - 1] - s_array[i - 1][j - 1];
            printf("%d ", s_array[i][j]);
        }
        printf("\n");
    }

}

int main() {
//    countStars();
//    sumDynamicRegions();
//    sumDynamicRegionsII();
//    maxRegions();
//    kidsQueue();
//    kidsQueueII();
//    paintArea();
//    threeBodyAttack();
//    spiralLen();
//    spiralLenII();
//    spiralLenIII();
//    diffSum();
    diffArr();

    return 0;
}
