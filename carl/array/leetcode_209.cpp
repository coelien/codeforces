#include<iostream>
#include<vector>
using namespace std;
vector<int> nums;
int target;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cin>>target;
    int l = 0, r = 0;
    int sum = 0;
    int min_len = nums.size()+1;
    for(;r<nums.size();r++){
        sum += nums[r];
        while(sum-nums[l]>= target)
            sum -= nums[l++];
        if(sum>=target && r-l+1<min_len){
            min_len = r-l+1;
        }
    }
    if(min_len == nums.size()+1)
        cout<<"0"<<endl;
    else
        cout<<min_len<<endl;
    return 0;

}