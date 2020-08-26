#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,i,j,s=0,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            s=s+a[j];
        }
    }
    printf("%d",s);
}
