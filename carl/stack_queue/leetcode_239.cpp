#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
    vector<int> nums{1};
    int k = 1;
    deque<int> window;
    vector<int> res;
    for(int i=0; i < nums.size(); ++i){
        int num = nums[i];
        while(!window.empty() && window.back()<num) window.pop_back();
        window.push_back(num);
        if(i>=k-1){
            res.push_back(window.front());
            if(nums[i-k+1] == window.front()) window.pop_front();
        }
    }

    for(auto num:res)
        cout<<num<<" ";
}