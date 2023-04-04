//
// Created by sixwa on 2022/12/7.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1e4 + 10;
int num[M];

void solu_1210() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int tmax = 0;
        int tmin = M;
        for (int j = i; j <= n; j++) {
            tmax = max(tmax, num[j]);
            tmin = min(tmin, num[j]);
            if (tmax - tmin == j - i)
                res++;
        }
    }
    cout << res;
}

const int N = 1e5 + 10;
const int pn = -1;
int A[N], B[N], C[N];

void solu_1236_fault() {
    // todo 看起来可行，实则不行，引以为戒，不要想当然的去做复杂的事情，而是用逻辑来引导
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    sort(A + 1, A + n + 1);
    sort(B + 1, B + n + 1);
    sort(C + 1, C + n + 1);

    A[0] = B[0] = C[0] = pn;
    int i = n, j = n, k = n;
    int cnt = 0;
    int flag = 1;
    int inc = 0;
    while (i >= 1 && j >= 1 && k >= 1) {
        int in = 0;
        while (B[j] >= C[k]) {
            j--;
            in++;
            if (in > 1)
                cnt += inc;
        }
        int tp = cnt;
        in = 0;
        while (A[i] >= B[j] && j > 0) {
            i--;
            in++;
            if (in > 1)
                cnt += tp;
        }
        int init = cnt;
        while (j > 0 && i > 0 && k > 0 && B[j] < C[k]) {
            if (flag) {
                if (in > 0)
                    cnt += (cnt + 1);
                else
                    cnt += (inc + 1);
            } else
                cnt++;
            k--;
            flag = 0;
        }
        inc = cnt - init;
        if (k == 0 && i >= 1 && j >= 1) {
            cnt = (inc * j + init) * i;
            break;
        }

        if (j == 0 && i >= 1) {
            cnt = cnt * i;
            break;
        }

        flag = 1;
    }
    cout << cnt;
}

int SA[N], SC[N];

void solu_1236() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        SA[A[i]]++;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
        SC[C[i]]++;
    }
    for (int i = 1; i < N; i++) {
        SA[i] = SA[i - 1] + SA[i];
        SC[i] = SC[i - 1] + SC[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res += (long long) (SA[B[i] - 1]) * (SC[N - 1] - SC[B[i]]);
    cout << res;
}

int find_less_b(int l, int r, int tar) {
    int st = l;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (A[mid] >= tar)
            r = mid - 1;
        else
            l = mid;
    }
    if (A[l] < tar)
        return l - st + 1;
    else
        return 0;
}

int find_more_b(int l, int r, int tar) {
    int ed = r;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (C[mid] <= tar)
            l = mid + 1;
        else
            r = mid;
    }
    if (C[l] > tar)
        return ed - l + 1;
    else
        return 0;
}

void solu_1235_bin() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    sort(A + 1, A + n + 1);
    sort(C + 1, C + n + 1);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int tar = B[i];
        int less = find_less_b(1, n, tar);
        int more = find_more_b(1, n, tar);
        res += (long long) less * more;
    }
    cout << res;
}

int interest_nums[10];

void solu_1245() {
    int n;
    cin >> n;
    interest_nums[0] = interest_nums[1] = interest_nums[2] = interest_nums[9] = 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (tmp) {
            int dig = tmp % 10;
            if (interest_nums[dig]) {
                sum += i;
                break;
            }
            tmp /= 10;
        }
    }
    cout << sum;
}

#include <sstream>

int cn[100010];

void solu_1204() {
    int n;
    cin >> n;
    int x;
    int max_x = 0;
    int min_x = 100000;

    string line;
    getline(cin, line);
    while (n--) {
        getline(cin, line);
        stringstream ssin(line);
        while (ssin >> x) {
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            cn[x]++;
        }
    }
    int rep_id = 0;
    int mis_id = 0;
    for (int i = min_x; i <= max_x; i++) {
        if (rep_id && mis_id)
            break;
        if (cn[i] == 0)
            mis_id = i;
        else if (cn[i] == 2)
            rep_id = i;
    }
    cout << mis_id << " " << rep_id;
}

int mon_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solu_466() {
    // 遍历所有回文数字，判断它是否是正确日期即可
    // 1000~9999
    int st, ed;
    cin >> st >> ed;
    int cnt = 0;
    for (int i = 1000; i <= 9999; i++) {
        int temp = i;
        int sum = 0;
        while (temp) {
            int x = temp % 10;
            sum = sum * 10 + x;
            temp /= 10;
        }
        int cu = i * 1e4 + sum;

        if (cu > ed || cu < st)
            continue;

        int day = sum % 100;
        int mon = sum / 100;

        if (mon > 12 || mon < 1)
            continue;
        if (i % 4 == 0 && i % 100 || i % 400 == 0)
            mon_day[2] = 29;
        else
            mon_day[2] = 28;
        int max_d = mon_day[mon];
        if (day > max_d || day < 1)
            continue;
        cnt++;
    }
    cout << cnt;
}

int Cnt = 0;
int dates[3];

void print_date(int y, int m, int d) {
    int year;
    // year/mon/day
    if (y >= 60)
        year = y + 1900;
    else
        year = y + 2000;
    bool run = (year % 4 == 0 && year % 100) || (year % 400) == 0;
    if (m <= 12 && m >= 1) {
        int max_d;
        if (m == 2 && run)
            max_d = mon_day[m] + 1;
        else
            max_d = mon_day[m];
        int res;
        if (d <= max_d && d >= 1) {
            res = year * 1e4 + m * 100 + d;
            dates[Cnt++] = res;
        }
    }
}

void solu_1229() {
    string str;
    cin >> str;
    int slot[3];
    int idx = 0;
    int tmp = 0;
    for (auto i: str) {
        if (i == '/') {
            slot[idx++] = tmp;
            tmp = 0;
        } else {
            tmp = tmp * 10 + i - '0';
        }
    }
    slot[idx] = tmp;

    // mon/day/year
    print_date(slot[2], slot[0], slot[1]);
    // year/mon/day
    print_date(slot[0], slot[1], slot[2]);
    // day/mon/year
    print_date(slot[2], slot[1], slot[0]);

    sort(dates, dates + 3);
    int pre = -1;
    for (int i: dates) {
        if (!i || i == pre) continue;
        pre = i;
        int y = i / 10000;
        int m = (i % 10000) / 100;
        int d = i % 100;
        printf("%d-%02d-%02d\n", y, m, d);
    }

}

int getSec(int h,int m,int s){
    return h*3600+m*60+s;
}
int getTime(){
    string line;
    getline(cin,line);
    if(line.back()!=')') line+=" (+0)";
    int h1,m1,s1,h2,m2,s2,d;
    sscanf(line.c_str(),"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
    return getSec(h2,m2,s2)-getSec(h1,m1,s1) + d*24*3600;

}
void solu_1231() {
    int n;
    scanf("%d", &n);
    string line;
    getline(cin,line);
    while (n--) {
        int time = (getTime() + getTime()) / 2;
        int h = time/3600;
        int m = (time%3600)/60;
        int s = (time%3600)%60;
        printf("%02d:%02d:%02d\n",h,m,s);
    }
}

typedef pair<int,int> PII;
int pri[N],la[N]; // la 表示最后一次有订单时的时刻
bool st[N];

PII ords[N];
void solu_1241(){
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ords[i] = {x,y};
    }
    sort(ords,ords+m);
    for(int i=0;i<m;){
        int j=i;
        while(j<m && ords[j] == ords[i]) j++;
        int time = ords[i].first, id = ords[i].second, cnt = j-i;
        // deal with the previous stuff
        pri[id] -= (time-la[id]-1);
        if(pri[id]<0) pri[id] = 0;
        if(pri[id]<=3) st[id] = false;
        // deal with current order
        pri[id] += (cnt*2);
        if(pri[id]>5) st[id] = true;
        la[id] = time;
        i = j;
    }
    for(int i=1;i<=n;i++){
        if(la[i]!=t){
            pri[i] -= (t-la[i]);
            if(pri[i]<=3) st[i] = false;
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(st[i]) res++;
    }
    printf("%d",res);

}
int nums[N];
int temp[N];
int combine(int st1, int ed1, int st2,int ed2){
    int i = st1, j = st2,k = st1;
    int res = 0;
    while(i<=ed1 && j<=ed2){
        if(nums[i]<=nums[j])
            temp[k++] = nums[i++];
        else{
            res += (ed1-i+1);
            temp[k++] = nums[j++];
        }
    }
    while(i<=ed1) temp[k++] = nums[i++];
    while(j<=ed2) temp[k++] = nums[j++];

    for(int i=st1;i<=ed2;i++)
        nums[i] = temp[i];
    return res;
}
int getRevNum(int st, int ed){
    if(st==ed) return 0;
    int mid = st+ed >> 1;
    int le = getRevNum(st,mid);
    int ri = getRevNum(mid+1,ed);

    int num = combine(st,mid,mid+1,ed);
    return le+ri+num;
}
void solu_788(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&nums[i]);
    int cnt = getRevNum(0,n-1);
    cout<<cnt;

}
int main() {
    //    solu_1210();
    //    solu_1236();
    //    solu_1235_bin();
    //    solu_1245();
    // solu_1204();
    // solu_466();
//    solu_1229();
//    solu_1231();
//    solu_1241();
    solu_788();
    return 0;
}