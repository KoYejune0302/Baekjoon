#include<stdio.h>
#include<algorithm>

using namespace std;

int n,k,a[110][2]={0},i,j,b[100010]={0};

int main(){
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(i=0;i<n;i++){
        for(j=k;j>=a[i][0];j--){
            b[j]=max(b[j],b[j-a[i][0]]+a[i][1]);
        }
    }
    printf("%d",b[k]);
}

