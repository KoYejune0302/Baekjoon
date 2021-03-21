#include<bits/stdc++.h>
using namespace std;

int a[10010],l,k,c;

bool chk(int x){
    int i,t=0,cnt=0;
    for(i=1;i<=k+1;i++){
        if(a[i]-a[i-1]>x) return false;
        if(a[i]-t>x){
            t=a[i-1];
            cnt++;
        }
    }
    if(cnt<=c) return true;
    else return false;
}

int f(int x){
    int i,t=0,cnt=0;
    for(i=1;i<=k+1;i++){
        if(a[i]-t>x){
            t=a[i-1];
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int i,h,t,p,q;
    scanf("%d %d %d",&l,&k,&c);
    for(i=1;i<=k;i++){
        scanf("%d",&a[i]);
    }
    a[k+1]=l;
    sort(a,a+k+2);
    h=0;
    t=l;
    while(h<t){
        int mid=(h+t)/2;
        if(chk(mid)) t=mid;
        else h=mid+1;
    }
    int r=k+1;
    for(i=k;i>=0;i--){
        if(a[r]-a[i]>h){
            r=i+1;
        }
    }
    if(f(h)<c) printf("%d %d",h,a[1]);
    else  printf("%d %d",h,a[r]);
    return 0;
}
