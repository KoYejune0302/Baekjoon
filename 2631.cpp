#include<stdio.h>
#include<algorithm>

using namespace std;

int n,a[210]={0},k[210][210]={0};

int main(){
    int i,j,m=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    k[1][a[1]]=1;
    for(i=2;i<=n;i++){
        for(j=1;j<=n;j++){
            k[i][j]=k[i-1][j];
        }
        k[i][a[i]]=1;
        for(j=1;j<=a[i];j++){
            k[i][a[i]]=max(k[i-1][j]+1,k[i][a[i]]);
        }
    }
    for(i=1;i<=n;i++){
        m=max(m,k[n][i]);
    }
    printf("%d",n-m);
}


