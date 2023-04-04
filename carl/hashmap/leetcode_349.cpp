#include<iostream>

#include<unordered_set>
#include<vector>

using namespace std;

int main(){
    vector<int> nums1{1,2,2,1}, nums2{2,2};
    vector<int>res;
    unordered_set<int> set,set0;
    for(int elem: nums1){
        set.insert(elem);
    }
    for(int elem:nums2){
        set0.insert(elem);
    }
    for(int elem:set0){
        if(set.count(elem)) res.push_back(elem);
    }
    
    for(int elem:res) cout<<elem<<" ";
    cout<<endl;
    return 0;
}