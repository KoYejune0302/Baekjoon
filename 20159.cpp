#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[100010],b[100010]={0},c[100010]={0},i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i<2){
            b[i]=a[i];
        }
        else{
            b[i]=a[i]+b[i-2];
        }
    }
    for(i=n-1;i>=0;i--){
        if(i>=n-2){
            c[i]=a[i];
        }
        else{
            c[i]=a[i]+c[i+2];
        }
    }
    int mx=max(c[0],c[1]);
    for(i=0;i<=n-2;i+=2){
        mx=max(mx,b[i]+c[i+3]);
    }
    for(i=0;i<=n-2;i+=2){
        mx=max(mx,b[i]+c[i+1]-a[n-1]);
    }
    printf("%d",mx);
}
