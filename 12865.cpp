#include<stdio.h>
#include<algorithm>

using namespace std;

int n,k,a[110][2]={0},i,j,b[110][100010]={0};

int main(){
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(j=a[0][0];j<=k;j++){
        b[0][j]=a[0][1];
    }
    for(i=1;i<n;i++){
        for(j=1;j<a[i][0];j++){
            b[i][j]=b[i-1][j];
        }
        for(j=a[i][0];j<=k;j++){
            b[i][j]=max(b[i-1][j],b[i-1][j-a[i][0]]+a[i][1]);
        }
    }
    printf("%d",b[n-1][k]);
}
