#include<stdio.h>

int m,n,a[110][110],b[110][110],r[4]={-1,0,1,0},c[4]={0,1,0,-1};

void f(int x, int y){
    int i;
    for(i=0;i<4;i++){
        if(x+r[i]>=0 && x+r[i]<m  && y+c[i]>=0 && y+c[i]<n && a[x+r[i]][y+c[i]]==1 && b[x+r[i]][y+c[i]]==0){
            b[x+r[i]][y+c[i]]=1;
        }
        else if(x+r[i]>=0 && x+r[i]<m  && y+c[i]>=0 && y+c[i]<n && a[x+r[i]][y+c[i]]==0 && b[x+r[i]][y+c[i]]!=2){
            b[x+r[i]][y+c[i]]=2;
            f(x+r[i], y+c[i]);
        }
    }
}

int main(){
    int i,j,s=0,cnt,t;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    cnt=1;
    while(cnt!=0){
        t=cnt;
        cnt=0;
        f(0,0);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(b[i][j]==1){
                    a[i][j]=0;
                    cnt=cnt+1;
                }
                b[i][j]=0;
            }
        }
        s++;
    }
    printf("%d\n%d",s-1,t);
    return 0;
}
/*
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
*/
