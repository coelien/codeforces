#include<iostream>
#include<vector>
using namespace std;
vector<int> nums;
int val;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cin>>val;
    int k=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[k++] = nums[i];
        }
    }
    cout<<k<<endl;
}