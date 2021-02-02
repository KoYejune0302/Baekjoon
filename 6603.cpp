#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(1){
        int a[15]={},b[15]={1,1,1,1,1,1,2},t=0,i;
        scanf("%d",&n);
        if(n==0) return 0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=6;i<n;i++){
            b[i]=2;
        }
        do{
            for(i=0;i<n;i++){
                if(b[i]==1){
                    printf("%d ",a[i]);
                }
            }
            printf("\n");
        }while(next_permutation(b,b+n));
        printf("\n");
    }
}
