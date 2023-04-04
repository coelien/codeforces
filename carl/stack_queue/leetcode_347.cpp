#include<iostream>
#include<vector>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;

struct Elem{
    int count=0;
    int num=0;
    Elem()=default;
    Elem(int cnt, int x):count(cnt),num(x){}
    bool operator<(const Elem &el) const{
        return count>el.count;
    } 
};

int main(){
    vector<int> nums{1,1,1,2,2,3,4,4,4,4};
    int k=3;
    unordered_map<int, Elem> map;
    vector<Elem> vec;
    for(auto num:nums){
        if(map.count(num)){
            map[num].count++;
        }else{
            Elem el(0,num);
            map[num] = el;
        }
    }
    priority_queue<Elem,vector<Elem>,less<Elem>> prique;

    for(auto pii : map){
        prique.push(pii.second);
        if(prique.size()>k){
            prique.pop();
        }
    }

    vector<int> res;
    while(!prique.empty()){
        res.push_back(prique.top().num);
        prique.pop();
    }

    for(auto num:res)
        cout<<num<<" ";
    
}