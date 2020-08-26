#include<stdio.h>
#include<algorithm>

using namespace std;

int n,a[20010]={0},b[20010]={0},c[20010]={0},i,j,m=1,t,k;

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        b[a[i]]=i;
    }
    for(i=1;i<=n;i++){
        if(c[i]!=1){
            t=i;
            c[t]=1;
            for(j=1;j<=n;j++){
                if(b[t]==i){
                   break;
                }
                t=b[t];
                c[t]=1;
            }
            k=__gcd(m,j);
            m=m/k*j;
        }
    }
    printf("%d",m);
}
