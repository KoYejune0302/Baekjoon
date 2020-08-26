#include<stdio.h>
#include<algorithm>

using namespace std;

int k[110][10010]={0},a[110][2]={0},n,m,t=0;

int main(){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i][0]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&a[i][1]);
    }
    k[0][0]=1;
    for(i=1;i<=n;i++){
        t=t+a[i][1];
        for(j=0;j<=t;j++){
            k[i][j]=k[i-1][j];
        }
        for(j=0;j<=t;j++){
            if(k[i-1][j]!=0){
                if(j+a[i][1]<=t){
                    k[i][j+a[i][1]]=max(k[i][j+a[i][1]],k[i-1][j]+a[i][0]);
                }
            }
        }
    }
    for(i=0;i<=t;i++){
        if(k[n][i]>=m){
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
