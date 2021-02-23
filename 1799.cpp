#include<bits/stdc++.h>
using namespace std;

int n,a[15][15],b[25],mx=0;

void f(int t,int m){
    mx=max(mx,t);
    if(mx>=t+2*n-m) return;
    if(m==2*n) return;
    int i,k,x,y;
    if(m>n) k=n-(m-n);
    else k=m;
    if(m<=n){
        x=m-1;
        y=0;
    }
    else{
        x=n-1;
        y=m-n;
    }
    for(i=0;i<k;i++){
        if(b[n-(x-i)+(y+i)]!=1 && a[x-i][y+i]==1){
            a[x-i][y+i]=2;
            b[n-(x-i)+(y+i)]=1;
            f(t+1,m+1);
            b[n-(x-i)+(y+i)]=0;
            a[x-i][y+i]=1;
        }
    }
    f(t,m+1);
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    f(0,1);
    printf("%d",mx);
}
