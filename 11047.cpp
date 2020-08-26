#include<stdio.h>

int main(){
    int n,m,a[11],cnt=0,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--){
        if(a[i]<=m){
            cnt=cnt+m/a[i];
            m=m%a[i];
        }
    }
    printf("%d",cnt);
}
