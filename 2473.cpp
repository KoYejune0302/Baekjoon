#include<bits/stdc++.h>
using namespace std;

int n,a[5010];

struct three{
    int a;
    int b;
    int c;
};

int main(){
    int i,j;
    three s;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    s={a[0],a[1],a[2]};
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            int t=a[i]+a[j],k;
            k=upper_bound(a+j+1,a+n,-t)-a;
            if(k-1>j && abs(t+a[k-1])<abs(s.a+s.b+s.c)){
                s={a[i],a[j],a[k-1]};
            }
            if(k<n && abs(t+a[k])<abs(s.a+s.b+s.c)){
                s={a[i],a[j],a[k]};
            }
        }
    }
    printf("%d %d %d",s.a,s.b,s.c);
    return 0;
}
