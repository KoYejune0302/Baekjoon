#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000010],d[2000'300],e[1000010];

int main(){
    scanf("%lld %lld",&n,&m);
    long long cnt=0,i,j,t=0,h;
    for(i=2;i<=1000'000+1000;i++){
        if(d[i]==1){
            continue;
        }
        e[t]=i;
        t++;
        for(j=i+i;j<=1000'000+1000;j=j+i){
            d[j]=1;
        }
    }
    for(i=0;i<t;i++){
        if(e[i]*e[i]>m){
            h=i;
            break;
        }
    }
    for(i=0;i<=h;i++){
        for(j=(n/(e[i]*e[i]))*(e[i]*e[i]);j<=m;j=j+e[i]*e[i]){
            if(j-n>=0) a[j-n]=1;
        }
    }
    for(i=0;i<=m-n;i++){
        cnt=cnt+a[i];
    }
    printf("%lld",(m-n+1)-cnt);
}
