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
        scanf("%d",&x);
        nums.push_back(x);
    }
    cin>>target;
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l+r>>1;
        if(nums[mid]==target){
            cout<<mid<<endl;
            break;
        }else if(nums[mid]<target){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    if(l>r){
        cout<<"not find"<<endl;
    }
    return 0;
}