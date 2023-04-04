//
// Created by sixwa on 2023/2/18.
//

#include<iostream>
#include<climits>
using namespace std;
const int N = 100010;
typedef pair<int, int> PII;
PII regs[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        regs[i] = {a, b};
    }

    int st = -INT_MAX, ed = -INT_MAX;
    int dead_day = 0, dead_time = 1;
    for (int i = 0; i < m; i++) {
        int a = regs[i].first, b = regs[i].second;
        if (ed != -INT_MAX) {
            if (a > ed + 1 && dead_time == 1) {
                dead_day = ed+1;
                dead_time = 0;
                break;
            } else if (a == ed) {
                dead_time += 1;
                continue;
            } else if (dead_time != 1) {
                dead_day = ed;
                break;
            } else {
                ed = b;
            }
        } else {
            st = a;
            ed = b;
        }
    }
    if(!dead_day && st==1 && ed ==n) cout<<"OK"<<endl;
    else if(st != 1) cout<<1<<" "<<0<<endl;
    else if(!dead_day && ed!=n) cout<<ed+1<<" "<<0<<endl;
    else cout<<dead_day<<" "<<dead_time<<endl;
    return 0;
}
