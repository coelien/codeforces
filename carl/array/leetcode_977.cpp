#include<iostream>
#include<vector>

using namespace std;

vector<int> nums;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<int> res;
    int neg = -1, pos = nums.size();
    int l = 0, r=nums.size()-1;
    while(l<r){
        int mid = (l+r+1)>>1;
        if(nums[mid]<0){
            l = mid;
        }else{
            r = mid -1;
        }
    }
    if(nums[l]<0){
        neg = l;
        if(l+1<nums.size()) pos = l+1;
    }else
        pos = 0;

    while(neg>=0 && pos<nums.size()){
        if(nums[neg]*nums[neg]<nums[pos]*nums[pos]){
            res.push_back(nums[neg]*nums[neg]);
            --neg;
        }else{
            res.push_back(nums[pos]*nums[pos]);
            ++pos;
        }
    }
    while(neg>=0){
        res.push_back(nums[neg]*nums[neg]);
        --neg;
    }
    while(pos<nums.size()){
        res.push_back(nums[pos]*nums[pos]);
        ++pos;
    }

    cout<< res.size()<<endl;

}