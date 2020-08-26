#include<stdio.h>
#include<algorithm>

int a[1000],k;
int search(int s,int f){
    int t;
    while(s<f){
        t=(s+f)/2;
        if(k>a[t]){
            s=t+1;
        }
        else{
            f=t;
        }
    }
    return k==a[s]?s:-1;

}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    printf("%d",search(0,n-1));
    printf("%d",std::lower_bound(&a[0],&a[n],k)-a);
    return 0;
}
