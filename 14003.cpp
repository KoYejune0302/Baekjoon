#include<stdio.h>
#include<algorithm>

using namespace std;

int s[1000010]={0},a[1000010]={0},k[1000010]={0};

int main(){
    int n,i,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    s[0]=-1000000010;
    s[1]=a[1];
    m=1;
    for(i=2;i<=n;i++){
        if(a[i]>s[m]){
            m++;
            s[m]=a[i];
            k[m]=a[i];
        }
        else{
            int t=lower_bound(s+1,s+m+1,a[i])-s;
            s[t]=a[i];
        }
    }
    printf("%d",m);
}

