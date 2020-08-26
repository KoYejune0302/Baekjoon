#include<stdio.h>

int main(){
    int n,a[30][30]={0},i,j,k,b[30][30]={0},s;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[i][j]==a[i][k]+a[k][j] && i!=k && j!=k){
                    b[i][j]=0;
                }
                if(a[i][j]>a[i][k]+a[k][j]){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    s=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(b[i][j]!=0){
                s=s+b[i][j];
            }
        }
    }
    printf("%d",s/2);
}
