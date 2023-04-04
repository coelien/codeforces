#include <iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        vector<int> x(n,0);
        res.push_back(x);
    }
    int i = 0, j = 0;
    int dir = 0; // directions right: 0 down: 1 left:2 up:3
    int rep = -1; // repeations in same length
    int len = n-1;
    int data = 1;
    while(len){
        int cnts = len;
        if(dir == 0){
            while(cnts--){
                res[i][j++] = data++;
            }
            
        }else if(dir == 1){
            while(cnts--){
                res[i++][j] = data++;
            }
        }else if(dir == 2){
            while(cnts--){
                res[i][j--]= data++;
            }
        }else{
            while(cnts--){
                res[i--][j] = data++;
            }
        }
        if(++rep==2){
            rep = 0;
            --len;
        }
        dir = (dir + 1) %4;
    }
    res[i][j] = data;
    for(auto vec : res){
        for(int elem:vec){
            cout<<elem<<" ";
        }
        cout<<endl;
    }
}