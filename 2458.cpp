#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,m,a[510][510]={0},i,j,k,p,q,s,cnt=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&p,&q);
        a[p][q]=1;
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
    s=0;
    for(i=1;i<=n;i++){
        cnt=0;
        for(j=1;j<=n;j++){
            if(a[j][i]!=0){
                cnt++;
            }
            if(a[i][j]!=0){
                cnt++;
            }
        }
        if(cnt==n-1){
            s++;
        }
    }
    printf("%d",s);
}


