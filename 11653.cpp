#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        while(n%i==0){
            printf("%d\n",i);
            n=n/i;
        }
    }
    return 0;
}
