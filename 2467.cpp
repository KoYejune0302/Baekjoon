#include<bits/stdc++.h>
using namespace std;

int n,a[100100];
pair<int, int> p;

bool chk(int x,int y){
    if(a[x]+a[y]<=0) return true;
    if(a[x]+a[y]>0) return false;
}

int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    p.first=a[0];
    p.second=a[1];
    for(i=0;i<n-1;i++){
        int h;
        h=upper_bound(a+i+1,a+n,-a[i])-a;
        /*
        while(h<t){
            int mid=(h+t+1)/2;
            if(chk(mid,i)) h=mid;
            else t=mid-1;
        }
        */
        if(h<=n-1 && abs(a[i]+a[h])<abs(p.first+p.second)){
            p.first=a[i];
            p.second=a[h];
        }
        if(h-1>i){
           if(abs(a[i]+a[h-1])<abs(p.first+p.second)){
                p.first=a[i];
                p.second=a[h-1];
            }
        }
    }
    printf("%d %d",p.first,p.second);
}
