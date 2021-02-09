#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000010]={},i,j;

int main(){
    scanf("%d %d",&m,&n);
    for(i=2;i<=n;i++){
        if(a[i]==1){
            continue;
        }
        for(j=i+i;j<=n;j=j+i){
            a[j]=1;
        }
    }
    for(i=m;i<=n;i++){
        if(a[i]==0 && i!=1){
            printf("%d\n",i);
        }
    }
    return 0;
}
