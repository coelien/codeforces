#include <iostream>
using namespace std;
const int pINF = 1e9;
int diff(int a,int b,int c){
    int minVal = pINF;
    minVal = min(minVal, abs(a-b));
    minVal = min(minVal, abs(c-b));
    minVal = min(minVal, abs(a-c));
    return minVal;
}

void working_week(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        // brute force
//        n-=3;
//        int maxVal = -pINF;
//        for(int i=1;i<=n/3;i++){
//            for(int j=i;j<=n/2;j++){
//                int rest = n-i-j;
//                maxVal = max(maxVal, diff(i,j,rest));
//            }
//        }
        // suppose l1<l2<l3
        // l1 should always be 1
        // so l2 + l3 = n-4
        // we would like to maximize min(l2-l1, l3-l2) = min(l2 - 1, n-4 - 2 * l2)
        // so when l2 = (n-3) / 3
        int maxVal = (n-3)/3 - 1;
        if((n-3)%3){
            int potential_2 = (n-3)/3+1;
            maxVal = max(maxVal,n-4-potential_2*2);
        }
        printf("%d\n",maxVal);
    }
}

double n,l,r,mid;
bool flag;
double q(double a){return a*a*a;}
int main(){
    cin>>n;
    l=-10000,r=10000;
    while(r-l>=1e-7){
        mid=(l+r)/2;
        if(q(mid)>=n) r=mid;
        else l=mid;
    }
    printf("%.6f",l);
    return 0;
}

//int main() {
//    working_week();
//    return 0;
//}
