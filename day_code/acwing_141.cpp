#include<iostream>
const int N = 1000010;
char s[N];
int ne[N];
using namespace std;

int main(){
    int n;
    int cnt=0;
    while(cin>>n && n!=0){
        printf("Test case #%d\n", ++cnt);
        scanf("%s",s+1);
        ne[1] = 0;
        for(int i=2,j=0;i<=n;i++){
            while(j && s[i] != s[j+1]) j = ne[j];
            if(s[i] == s[j+1]) ++j;
            ne[i] = j;
        }

        for(int i=2;i<=n;i++){
            int recur = i - ne[i];
            if(recur != i && i % recur == 0) printf("%d %d\n",i,i/recur);
        }
        printf("\n");
    }
    return 0;
}