#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,a[1010],i,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    if(a[0]==1){
        for(i=1;i<n;i++){
            t=t+a[i-1];
            if(a[i]>t+1){
                break;
            }
        }
        if(i==n){
            t=t+a[n-1];
        }
        printf("%d",t+1);
    }
    else{
        printf("%d",1);
    }
}
