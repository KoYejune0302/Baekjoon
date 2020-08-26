#include<stdio.h>

int main(){
    int n,m,i,b[50]={0},s=1,a[50]={1,1,2,0};
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    for(i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    b[m+1]=n+1;
    for(i=1;i<=m+1;i++){
        s=s*a[(b[i]-b[i-1])-1];
    }
    printf("%d",s);
    return 0;
}
