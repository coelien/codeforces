#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums1{1,2};
    vector<int> nums2{-2,-1};
    vector<int> nums3{-1,2};
    vector<int> nums4{0,2};
    unordered_map<int,int> unmap;
    for(int e1 :nums1){
        for(int e2:nums2){
            ++unmap[e1+e2];
        }
    }
    int res = 0;
    for(int e3:nums3){
        for(int e4: nums4){
            int key = -(e4+e3);
            res += unmap[key];
        }    
    }
    cout<<res<<endl;
}