//
// Created by sixwa on 2023/2/20.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    string str;
    cin>>n;
    cin>>str;
    int cnt = 0;
    for(int i=0,j;i<n;){
        if(str[i]=='x'){
            j = i;
            while(j<n && str[j]=='x') j++;
            int len = j-i;
            if(len>=3) cnt += (len-2);
            i = j;
        }else i++;
    }
    cout<<cnt<<endl;
//    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//    auto p = ia;
//    auto q = &ia[2];
//    int (*r) [4] = ia;
//    cout<<*p<<endl;
//    cout<<*(*q+1)<<endl;
//    cout<<*(*r+1)<<endl;
}