#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,k,a[110]={0},i,j,b[10010];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=k;i++){
        b[i]=10001;
    }
    b[0]=0;
    for(i=1;i<=k;i++){
        for(j=0;j<n;j++){
            if(i-a[j]>=0){
                b[i]=min(b[i-a[j]]+1,b[i]);
            }
        }
    }
    if(b[k]==10001){
        printf("-1");
        return 0;
    }
    printf("%d",b[k]);
    return 0;
}
