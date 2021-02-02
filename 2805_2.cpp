#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000010];

bool chk(int mid){
    long long s=0;
    int i;
    for(i=0;i<n;i++){
        if(a[i]>mid){
            s=s+a[i]-mid;
        }
    }
    return s>=m;
}

int main(){
    int i,h,t;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    h=0;
    t=a[n-1];
    while(h<t){
        int mid = (h+t+1)/2;
        if(chk(mid)){
            h= mid;
        }
        else{
            t=mid-1;
        }
    }
    printf("%d",h);
    return 0;
}
