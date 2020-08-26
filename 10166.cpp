#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,i,j,a[2010][2010]={0},cnt=0,t;

int main(){
    scanf("%d %d",&n,&m);
    for(i=n;i<=m;i++){
        for(j=1;j<=i;j++){
            t=__gcd(i,j);
            if(a[i/t][j/t]==0){
                cnt++;
                a[i/t][j/t]=1;
            }
        }
    }
    printf("%d",cnt);
}
