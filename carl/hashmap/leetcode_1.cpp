#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums{2,7,11,15};
    vector<int> res;
    unordered_map<int,int> omap;
    int target = 9;
    for(int i=0;i<nums.size() ;i++){
        int another = target - nums[i];
        if(omap.count(another)){
            res.push_back(i);
            res.push_back(omap[another]);
            return 0;
        }
        omap[nums[i]]=i;
    }
    return 0;
}