#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,i,a[310]={0},b[2][310]={0},cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    b[0][1]=a[1];
    b[1][1]=0;
    for(i=2;i<=n;i++){
        b[0][i]=a[i]+max(b[0][i-2],b[1][i-2]);
        b[1][i]=a[i]+b[0][i-1];
    }
    printf("%d",max(b[0][n],b[1][n]));
}
