#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000010],k;

bool chk(int x){
    int i,p=0,r=k;
    for(i=1;i<=m;i++){
        if(p==0 && a[i]==1){
            p=i;
            break;
        }
    }
    for(i=p;i<=m;i++){
        if(a[i]==1){
            r=r-1;
            i=i+x-1;
        }
    }
    if(r>=0) return true;
    else return false;

}

int main(){
    int t,i,x,y,p=0,s,f;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&k,&t);
    for(i=0;i<t;i++){
        scanf("%d %d",&x,&y);
        p=max(p,x);
        a[y]=1;
    }
    s=p;
    f=n;
    while(s<f){
        int mid=(s+f)/2;
        if(chk(mid)) f=mid;
        else s=mid+1;
    }
    printf("%d",s);
}
