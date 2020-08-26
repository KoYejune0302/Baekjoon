#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,m,a[410][410]={0},i,j,k,p,q,r,s,cnt=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&p,&q,&r);
        a[p][q]=r;
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[i][k]!=0 && a[k][j]!=0){
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
    s=1000000;
    for(i=1;i<=n;i++){
        if(a[i][i]!=0){
            s=min(s,a[i][i]);
        }
        else{
            cnt++;
        }
    }
    if(cnt==n){
        printf("-1");
    }
    else{
        printf("%d",s);
    }
}

