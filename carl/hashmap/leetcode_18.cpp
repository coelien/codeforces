#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long LL;
int main(){
    vector<int> nums{-2,-1,-1,1,1,2,2};
    int target =0;
    vector<vector<int>> res;
        if(nums.size()<4) return 0;
        sort(nums.begin(),nums.end());

        for(int a = 0;a<nums.size()-3;++a){
            if(a>0 && nums[a-1]==nums[a]) continue;
            for(int b = a+1;b<nums.size()-2;++b){
                int c = b+1;
                int d = nums.size()-1;
                
                if(b>a+1 && nums[b-1]==nums[b]) continue;
                while(c<d){
                    if((LL)nums[a]+nums[b]+nums[c]+nums[d]>target) {
                        --d;
                    }
                    else if((LL)nums[a]+nums[b]+nums[c]+nums[d]<target) {
                        ++c;
                    }
                    else{
                        vector<int> tmp{nums[a],nums[b],nums[c],nums[d]};
                        res.push_back(tmp);
                        while(c<d && nums[d-1]==nums[d]) --d;
                        while(c<d && nums[c+1]==nums[c]) ++c;
                        --d;
                        ++c;
                        
                    }
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