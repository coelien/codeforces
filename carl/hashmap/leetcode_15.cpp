#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());

    int a = 0;
    int b = 1;
    int c = nums.size()-1;
    for(;a<nums.size()-2;++a){
        if(nums[a]>0) break;
        b = a+1;
        c = nums.size()-1;
        if(a>0 && nums[a]==nums[a-1]) continue;

        while(b<c){
            if(nums[a]+nums[b]+nums[c]>0) --c;
            else if(nums[a]+nums[b]+nums[c]<0) ++b;
            else{
                vector<int> tmp{nums[a],nums[b],nums[c]};
                res.push_back(tmp);
                while(b<c && nums[c-1]==nums[c]) --c;
                while(b<c && nums[b+1]==nums[b]) ++b;
                --c;
                ++b;
            }
            
        }

    }

    for(auto tu:res){
        for(int el:tu){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}