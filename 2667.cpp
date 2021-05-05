#include<bits/stdc++.h>
using namespace std;

int n,a[30][30],b[30][30],cnt=0,s[1000];

void f(int x,int y){
    int i,r[4]={1,0,-1,0},c[4]={0,1,0,-1};
    s[cnt]++;
    b[x][y]=0;
    for(i=0;i<4;i++){
        if(x+r[i]>=0 && x+r[i]<n && y+c[i]>=0 && y+c[i]<n && a[x+r[i]][y+c[i]]==1 && b[x+r[i]][y+c[i]]==1){
            f(x+r[i],y+c[i]);
        }
    }
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%1d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==1 && b[i][j]==1){
                cnt++;
                f(i,j);
            }
        }
    }
    printf("%d\n",cnt);
    sort(s+1,s+cnt+1);
    for(i=1;i<=cnt;i++){
        printf("%d\n",s[i]);
    }
}
