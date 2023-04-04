#include<iostream>
#include<stack>
const int N = 32;
const int M = 100010;
int son[N*M][2];
int idx = 1;
// int count[N];

int nums[M];
using namespace std;

void insert(stack<int> &st){
    int cu = 0;
    while(st.size()!=32) st.push(0);
    while(!st.empty()){
        int k = st.top();
        st.pop();
        if(!son[cu][k]) son[cu][k] = idx++;
        cu = son[cu][k];
    }
    // count[cu]++;
}

int query(stack<int> &tar){
    int cu = 0;
    int base = 0;
    while(tar.size()!=32) tar.push(0);
    while(!tar.empty()){
        int k = tar.top();
        tar.pop();
        if(son[cu][!k]) {
            base = base * 2 +1;
            cu = son[cu][!k];
        }else{
            base = base * 2;
            cu = son[cu][k];
        }
        
    }
    return base;
}

int main(){
    int n;
    cin>>n;
    stack<int> bi;
    for(int i=0;i<n;i++) {
        scanf("%d",&nums[i]);
        int x = nums[i];
        while(x){
            bi.push(x%2);
            x/=2;
        }
        insert(bi);
    }
    int max_res = 0;
    for(int i=0;i<n-1;i++){
        int x = nums[i];
        while(x){
            bi.push(x%2);
            x/=2;
        }
        max_res = max(query(bi),max_res);
    }
    cout<<max_res<<endl;
    return 0;
}