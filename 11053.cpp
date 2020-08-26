#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,i,j,m=0,a[1010],s[1010];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        s[i]=1;
        for(j=0;j<=i;j++){
            if(a[j]<a[i] && s[j]+1>s[i]){
                s[i]=s[j]+1;
            }
        }
    }
    for(i=0;i<n;i++){
        m=max(m,s[i]);
    }
    printf("%d",m);
}
