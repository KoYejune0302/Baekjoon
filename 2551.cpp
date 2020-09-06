#include<bits/stdc++.h>
using namespace std;

long long n,a[5000010];

int main(){
    long long i,j,s1,s2,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum=sum+a[i];
    }
    sort(a,a+n);
    if(n%2==0){
        s1=a[n/2-1];
    }
    else{
        s1=a[n/2];
    }

    if(sum%n>(double)n/2){
        s2=sum/n+1;
    }
    else{
        s2=sum/n;
    }
    printf("%lld %lld",s1,s2);
}
