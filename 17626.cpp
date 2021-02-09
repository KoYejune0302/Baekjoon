#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[50010]={},i,j;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        a[i]=n;
    }
    for(i=1;i<=n;i++){
        for(j=int(sqrt(i));j>=1;j--){
            if(i==j*j){
                a[i]=1;
                break;
            }
            if(a[i]>=1+a[i-(j*j)]){
                a[i]=1+a[i-(j*j)];
            }

        }
    }
    printf("%d",a[n]);
}
