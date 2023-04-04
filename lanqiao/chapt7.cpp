//
// Created by sixwa on 2023/2/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
int stock[N];

void stockPurchase() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &stock[i]);
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += max(0, stock[i] - stock[i - 1]);
    }
    cout << sum << endl;
}

int warehouse[N];

void warehousePosition() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &warehouse[i]);
    sort(warehouse, warehouse + n);
    int pos = warehouse[n / 2];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += (abs(warehouse[i] - pos));
    cout << sum << endl;

}

typedef long long LL;
LL c[N];

void candyPassing() {
    int n;
    scanf("%d", &n);
    LL a_avg = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        a_avg += c[i];
    }
    a_avg /= n;
    c[n - 1] = a_avg - c[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        c[i] = c[i + 1] + a_avg - c[i];
    }
    sort(c, c + n);
    LL sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(c[i] - c[n / 2]);
    cout << sum << endl;
}

struct Isl {
    double l, r;

    bool operator<(const Isl &other) const {
        return r < other.r;
    }
};

Isl islands[N];

void radarDetect() {
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        if (y > d) {
            cout << -1 << endl;
            return;
        }
        double al = sqrt(d * d - y * y);
        islands[i] = {x - al, x + al};
    }

    sort(islands, islands + n);

    int radar = 0;
    double pil = -DBL_MAX;
    for (int i = 0; i < n; i++) {
        auto[l, r] = islands[i];
        if (l <= pil) continue;
        else {
            radar++;
            pil = r;
        }
    }
    cout << radar << endl;
}

int pocket[N];

void payCheck() {
    int n;
    LL S;
    cin >> n >> S;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pocket[i]);
    }
    sort(pocket, pocket + n);
    double avg = S / (n * 1.0);
    double std = 0;
    double avg_debt = 0, debt = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (pocket[i] < avg) {
            std += (avg - pocket[i]) * (avg - pocket[i]);
            debt += (avg - pocket[i]);
//            cout << avg - pocket[i] << endl;
        } else {
            if (flag == 0) avg_debt = debt / (n - i);
            double remain = pocket[i] - avg;
            if (flag == 1 || avg_debt <= remain) {
                debt -= avg_debt;
                flag = 1;
                std += avg_debt * avg_debt;
//                cout << avg_debt << endl;
            } else {
                debt -= remain;
                std += remain * remain;
//                cout << remain << endl;
            }
        }

    }
    printf("%.4lf", sqrt(std / n));
}

int num[N];
vector<int> selects;
const int mod = 1000000009;

bool cmp(const int a, const int b) {
    return abs(a) > abs(b);
}

LL mul(int a, int b) {
    if (a == 0 || b == 0) return 0;
    if (a < 0 && b < 0 || a > 0 && b > 0) {
        return ((LL) a * b) % mod;
    } else {
        return -((-(LL) a * b) % mod);
    }
}
LL find_even(int k, int l, int r){
    int i = l;
    int j = r;
    LL res = 1;
    while(k){
        bool neg = false, opt = false;
        LL temp_neg=1,temp_opt=1;
        if(num[j]>=0 && num[j-1]>=0){
            opt = true;
            temp_opt = (LL)num[j-1]*num[j];
        }
        if(num[i]<0 && num[i+1]<0){
            neg = true;
            temp_neg = (LL)num[i]*num[i+1];
        }
        if(opt && neg){
            if(temp_neg>temp_opt){
                res = (res * temp_neg) % mod;
                i+=2;
                k-=2;
                continue;
            }else{
                res = (res * temp_opt)%mod;
                j-=2;
                k-=2;
                continue;
            }
        }
        if(opt){
            res = (res * temp_opt)%mod;
            j-=2;
            k-=2;
            continue;
        }
        if(neg){
            res = (res * temp_neg) % mod;
            i+=2;
            k-=2;
            continue;
        }
    }
    return res;
}
void maxProduct() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    sort(num, num + n);
    LL res = 1;
    if (k == n) {
        for (int i = 0; i < k; i++)
            res = (res * num[i]) % mod;
    } else {
        if (k % 2) {
            if (num[n - 1] < 0) {
                for (int i = n - 1; i >= n - k; i--)
                    res = (res * num[i]) % mod;
            } else {
                res = (res * num[n - 1]) % mod;
                res = (res * find_even(k - 1, 0, n - 2)) % mod;
            }
        }else{
            res = find_even(k,0,n-1);
        }
    }
    cout << res << endl;
}

void postfixExpression() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m + 1; i++) scanf("%d", &num[i]);
    sort(num, num + n + m + 1);

    LL ans = 0;
    if(m==0){
        for(int i=0;i<n+m+1;i++) ans += num[i];
    }
    else{
        ans = num[m+n] - num[0];
        for(int i=1;i<n+m;i++) ans+=abs(num[i]);
    }

    cout << ans << endl;
}
const int U = 300010;
int sold[U];
LL sum_s[U];
LL temp_s[U];
bool temp_b[U];
void psychoPassing(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        sum_s[0] = 0;
        memset(temp_b,0,sizeof temp_b);
        for(int i=1;i<=n;i++) scanf("%d",&sold[i]);
        for(int i=1;i<=n;i++) sum_s[i] = sum_s[i-1]+sold[i];
        LL s0 = sum_s[0];
        LL sn = sum_s[n];
        if(s0>sn) swap(s0,sn);
        sort(sum_s,sum_s+n+1);
        int a=0,b=0;

        for(int i=0;i<=n;i++){
            if(sum_s[i]==s0){
                a = i;
                continue;
            }
            if(sum_s[i]==sn){
                b = i;
            }
        }
        int k=0;
        for(int i=a;i>=0;i-=2){
            if(!temp_b[i]){
                temp_b[i] = true;
                temp_s[k++] = sum_s[i];
            }
        }
        int j = n;
        for(int i=b;i<=n;i+=2){
            if(!temp_b[i]){
                temp_b[i] = true;
                temp_s[j--] = sum_s[i];
            }
        }
        for(int i=0;i<=n;i++){
            if(!temp_b[i]){
                temp_b[i]= true;
                temp_s[k++] = sum_s[i];
            }
        }
        LL max_p = 0;
        for(int i=1;i<=n;i++){
            LL te = (temp_s[i]-temp_s[i-1]);
            max_p = max(max_p,abs(te));
        }
        cout<<max_p<<endl;
    }
}
int main() {
//    stockPurchase();
//    warehousePosition();
//    candyPassing();
//    radarDetect();
//    payCheck();
//    maxProduct();
//    postfixExpression();
    psychoPassing();
}