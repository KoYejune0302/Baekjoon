#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,m,a[110][110]={0},i,j,k,p,q,r;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&p,&q,&r);
        if(a[p][q]==0){
            a[p][q]=r;
        }
        else{
            a[p][q]=min(r,a[p][q]);
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[i][k]!=0 && a[k][j]!=0 && i!=j){
                    if(a[i][j]==0){
                        a[i][j]=a[i][k]+a[k][j];
                    }
                    else{
                        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
