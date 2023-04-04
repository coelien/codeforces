#include<iostream>
#include<stack>

using namespace std;
const int N = 100010;
int nums[N];
int main(){
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++) scanf("%d",&nums[i]);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=nums[i]) st.pop();
        if(st.empty()) printf("%d ",-1);
        else printf("%d ",st.top());
        st.push(nums[i]);
    }

}