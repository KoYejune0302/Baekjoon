#include<stdio.h>

int n,m,a[40]={0},k[40][40010]={0},t;

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    k[0][a[0]]=1;
    for(i=1;i<n;i++){
        k[i][a[i]]=1;
        for(j=1;j<=40000;j++){
            if(k[i-1][j]==1){
                k[i][j]=1;
                if(j+a[i]<=40000){
                    k[i][j+a[i]]=1;
                }
                if(j>=a[i]){
                    k[i][j-a[i]]=1;
                }
                else{
                    k[i][a[i]-j]=1;
                }
            }
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&t);
        if(k[n-1][t]==1){
            printf("Y ");
        }
        else{
            printf("N ");
        }
    }
}
