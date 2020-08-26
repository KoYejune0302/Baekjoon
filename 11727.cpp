#include<stdio.h>

int main(){
    int n,i,a[1010]={0};
    scanf("%d",&n);
    a[1]=1;
    a[2]=3;
    for(i=3;i<=n;i++){
        a[i]=a[i-1]+a[i-2]*2;
        a[i]=a[i]%10007;
    }
    printf("%d",a[n]%10007);
}
