#include<bits/stdc++.h>
using namespace std;

int n,a[11][11],mx=0;

bool ch(int r,int c){
    int i,j;
    int p[4]={1,1,-1,-1},q[4]={-1,1,1,-1};
    if(a[r][c]!=1){
        return false;
    }
    for(i=0;i<4;i++){
        for(j=1;j<=n;j++){
            if(r+p[i]*j<0 || r+p[i]*j>=n || c+q[i]*j<0 || c+q[i]*j>=n){
                break;
            }
            if(a[r+p[i]*j][c+q[i]*j]==2){
                return false;
            }
        }
    }
    return true;
}

void f(int t,int x, int y){
    mx=max(mx,t);
    if(y!=n-1){
        if(ch(x,y)){
            a[x][y]=2;
            f(t+1,x,y+1);
            a[x][y]=1;
        }
        f(t,x,y+1);

    }
    else if(x!=n-1){
        if(ch(x,y)){
            a[x][y]=2;
            f(t+1,x+1,0);
            a[x][y]=1;
        }
        f(t,x+1,0);
    }
    return;
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    f(0,0,0);
    printf("%d",mx);
}
