#include<stdio.h>

int a,b,d,n,k[1000010]={0},i,s=0,j;

int main(){
    scanf("%d %d %d %d",&a,&b,&d,&n);
    k[0]=1;
    k[a]=1;
    for(i=a+1;i<=n;i++){
        if(i-b>=0){
            k[i]=(k[i-1]+k[i-a]-k[i-b]+1000)%1000;
        }
        else{
            k[i]=(k[i-1]+k[i-a])%1000;
        }
    }
    if(n>=d){
        for(i=n-d+1;i<=n;i++){
            s=(s+k[i])%1000;
        }
    }
    else{
        for(i=0;i<=n;i++){
            s=(s+k[i])%1000;
        }
    }
    printf("%d",s%1000);
}
