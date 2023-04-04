#include <iostream>
#include<algorithm>
#include<sstream>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    
    char delim = ';';
    int x=0,y=0;
    for(auto iter=s.begin(),iter2=s.begin();iter!=s.end();++iter2){
        if(*iter2 == delim){
            if(iter == iter2) {
                ++iter;
                continue;
            }
            string temp;
            copy(iter,iter2,back_inserter(temp));
            iter = iter2+1;
            istringstream in(temp);
            char dir;
            if(!(in>>dir)) continue;
            if(dir!='A' && dir!='W' && dir!='S'&& dir!='D') continue;
            int dist;
            if(!(in>>dist)) continue;
            if(dist<0 || dist>100) continue;
            if(in>>dir) continue;
            switch (dir)
            {
                case 'A':
                    x-=dist;
                    break;
                case 'W':
                    y+=dist;
                    break;
                case 'S':
                    y-=dist;
                    break;
                case 'D':
                    x+=dist;
                default:
                    break;
            }
            
        }
    }
    cout<<x<<","<<y<<endl;
}
// 64 位输出请用 printf("%lld")