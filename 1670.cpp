#include<stdio.h>

int main(){
    long long n,i,j,a[10010]={1,0,1,0,2};
    scanf("%lld",&n);
    for(i=6;i<=n;i=i+2){
        for(j=2;j<=i;j=j+2){
            a[i] = a[i] + (a[i-j]*a[j-2])%987654321;
            a[i]=a[i]%987654321;
        }
    }
    printf("%lld",a[n]);
}
