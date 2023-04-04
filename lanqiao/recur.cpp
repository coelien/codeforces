//
// Created by sixwa on 2022/10/26.
//

#include<iostream>
#include <vector>

using namespace std;

//92. 递归实现指数型枚举
void solu_92_no_rec() {
    int n;
    cin >> n;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >> (n - j) & 1) printf("%d ", j);
        }
        puts("");
    }
}

vector<int> vec;

void dfs_92(int n, int l) {
    if (l == n) {
        for (auto i: vec) {
            printf("%d ", i);
        }
        puts("");
        return;
    }
    //select l;
    vec.push_back(l + 1);
    dfs_92(n, l + 1);
    vec.pop_back();
    //no select
    dfs_92(n, l + 1);
}

void solu_92_with_rec() {
    int n;
    cin >> n;
    dfs_92(n, 0);
}

//94. 递归实现排列型枚举
//#include <unordered_set>
//unordered_set<int> myset;
bool used[20];

void dfs_94(int n, int l) {
    if (n == l) {
        for (auto i: vec) {
            printf("%d ", i);
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            vec.push_back(i);
            used[i] = true;
            dfs_94(n, l + 1);
            used[i] = false;
            vec.pop_back();
        }
    }

}

void solu_94() {
    int n;
    cin >> n;
    dfs_94(n, 0);

}

const int N = 50;
int mem[N];

int fibo(int n) {
    if (mem[n]) return mem[n];
    if (n == 1 || n == 2)
        mem[n] = 1;
    else
        mem[n] = fibo(n - 1) + fibo(n - 2);
    return mem[n];
}

void solu_717() {
    int n;
    cin >> n;
    fibo(n - 1);
    for (int i = 0; i < n; i++)
        cout << mem[i] << " ";

}

int n, m;

void dfs_93(int l) {
    if (l == m) {
        for (int a: vec)
            printf("%d ", a);
        puts("");
        return;
    }
    int last = 0;
    if (vec.size()) last = vec.back();
    for (int i = last + 1; i <= n; i++) {
        vec.push_back(i);
        dfs_93(l + 1);
        vec.pop_back();
    }
}

void solu_93() {
    cin >> n >> m;
    dfs_93(0);
}

vector<vector<int>> vec_bag;

void permute(int l) {
    // store 1-9 permutations
    if (l == 9) {
//        vector<int> new_vec = vector<int>(vec.begin(),vec.end());
        vec_bag.push_back(vec);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            vec.push_back(i);
            permute(l + 1);
            used[i] = false;
            vec.pop_back();
        }
    }
}

int get_num(int l, int r, vector<int> &it) {
    int sum = 0;
    for (int i = l; i < r; i++) {
        sum = sum * 10 + it[i];
    }
    return sum;
}

void solu_1209_brute() {
    cin >> n; // n<1e6
    permute(0);
    int cnt = 0;
//    printf("permutations num: %d\n",vec_bag.size());
    for (auto item: vec_bag) {

        for (int i = 1; i <= 8; i++) {
            for (int j = i + 1; j <= 8; j++) {
                int a = get_num(0, i, item);
                int b = get_num(i, j, item);
                int c = get_num(j, 9, item);
                if (b % c == 0 && n == (a + b / c)) {
//                    printf("a:%d b:%d c:%d\n",a,b,c);
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}

bool tmp[20];
int cnt;

bool check(int a, int c) {
    int b = n * c - a * c;
    if (!a || !b || !c) return false;
    memcpy(tmp, used, sizeof used);
    while (b) {
        int x = b % 10;
        b /= 10;
        if (!x || tmp[x]) return false;
        tmp[x] = true;
    }
    for (int i = 1; i <= 9; i++) {
        if (!tmp[i])
            return false;
    }
    return true;

}

void dfs_c(int l, int a, int c) {
    if (l >= 9) return;
    if (check(a, c)) cnt++;
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs_c(l + 1, a, c * 10 + i);
            used[i] = false;
        }
    }
}

void dfs_a(int l, int a) {
    if (a >= n || l >= 8) return;
    dfs_c(l, a, 0);
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs_a(l + 1, a * 10 + i);
            used[i] = false;
        }
    }
}

void solu_1209_optim() {
    cin >> n;
    dfs_a(0, 0);
    cout << cnt << endl;
}

const int M = 110;
char init_str[M];
char end_str[M];

void flip(int i) {
    if (init_str[i] == 'o') init_str[i] = '*';
    else init_str[i] = 'o';
}

void solu_1208() {
    scanf("%s", init_str + 1);
    scanf("%s", end_str + 1);
    int cnt = 0;
    for (int i = 1; init_str[i]; i++) {
        if (init_str[i] != end_str[i]) {
            init_str[i] = end_str[i];
            if (init_str[i + 1]) flip(i + 1);
            cnt++;
        }
    }
    cout << cnt;
}

int directions[6] = {0, 0, -1, 0, 1, 0};
int sq[N][N];
int cpy[N][N];
char in_str[N];

void change_stat(int i, int j) {
    for (int k = 0; k < 5; k++) {
        int x = i + directions[k];
        int y = j + directions[k + 1];
        if (x >= 0 && y >= 0 && x < 5 && y < 5) sq[x][y] = !sq[x][y];
    }
}

void solu_95() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 5; i++) {
            cin >> in_str;
            for (int j = 0; in_str[j]; j++) {
                sq[i][j] = in_str[j] - '0';
            }
        }
//        for(int i=0;i<5;i++) {
//            for (int j = 0; j < 5; j++)
//                printf("%d", sq[i][j]);
//            puts("");
//        }
        memcpy(cpy,sq,sizeof sq);
        int min_step = 25;
        for (int i = 0; i < 1 << 5; i++) {
            // back up
            memcpy(sq,cpy,sizeof sq);
            int step = 0;
            int j;
            bool vali = true;
            for (j = 0; j < 5; j++)
                if ((i >> j) & 1) {// 开关为关闭状态
                    change_stat(0, 4 - j);
                    step++;
                }
//            for (int p = 0; p < 5; p++) {
//                for (int q = 0; q < 5; q++)
//                    printf("%d", sq[p][q]);
//                puts("");
//            }
//            puts("");
            for (int k = 0; k < 5; k++) {
                for (j = 0; j < 5; j++) {
                    if (!sq[k][j]) {// 开关为关闭状态
                        if (k == 4) {
                            vali = false;
                            break;
                        }
                        change_stat(k + 1, j);
                        step++;
                    }
                }
            }
//            if (step > 6) vali = false;
            if (vali) min_step = min(min_step, step);
        }
        if (min_step > 6)
            cout << -1 << endl;
        else
            cout << min_step << endl;
    }
}
int board[4][4];
int temp_board[4][4];
char temp_str[5];
typedef pair<int,int> pii;
vector<pii> pairs,res;
void oper(int i, int j){
    for(int c=0;c<4;c++) temp_board[i][c]=!temp_board[i][c];
    for(int r=0;r<4;r++) temp_board[r][j]=!temp_board[r][j];
    temp_board[i][j] = !temp_board[i][j];
}
void solu_116(){
    for(int i=0;i<4;i++){
        cin>>temp_str;
        for(int j=0;j<4;j++){
            if(temp_str[j]=='-') board[i][j]=1;
        }
    }
    int min_step = 17;
    for(int i=0;i<1<<16;i++) {
        int step = 0;
        pairs.clear();
        int now = i;
        memcpy(temp_board,board, sizeof board);
        for (int j = 0; j < 16; j++) {
            if (i >> j & 1) {
                oper(j / 4, j % 4);
                // now ^= temp_board(j / 4, j % 4);
                pairs.push_back({j / 4, j % 4});
                step++;
            }
        }
        bool can_sol = true;
        for (int p = 0; p < 4; p++)
            for (int q = 0; q < 4; q++)
                if (!temp_board[p][q]) {
                    can_sol = false;
                    break;
                }
        if (can_sol) {
            if (step < min_step) {
                min_step = step;
//                copy(pairs.begin(), pairs.end(), res);
                res.clear();
                for (auto elem: pairs)
                    res.push_back(elem);
            }
        }
    }
    cout<<min_step<<endl;
    for (auto elem: res)
        printf("%d %d\n", elem.first+1, elem.second+1);

}

int main() {
//    solu_92_no_rec();
//    solu_92_with_rec();
//    solu_94();
//    solu_93();
//    solu_717();
//    solu_1209_brute();
//    solu_1209_optim();
//    solu_1208();
//    solu_95();
    solu_116();
    return 0;
}
