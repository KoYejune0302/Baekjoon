#include<stdio.h>

int a[55][55],m,n;
void f(int x, int y){
    int r[4]={-1,0,1,0},c[4]={0,1,0,-1},i;
    for(i=0;i<4;i++){
        if(y+c[i]<m && y+c[i] >=0 && x+r[i]<n && x+r[i] >=0 && a[x+r[i]][y+c[i]]==1){
            a[x+r[i]][y+c[i]]=0;
            f(x+r[i],y+c[i]);
        }
    }
}

int main(){
    int t,k,i,j,x,y,cnt;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d",&m,&n,&k);
        for(j=0;j<k;j++){
           scanf("%d %d",&x,&y);
           a[y][x]=1;
        }
        cnt=0;
        for(x=0;x<n;x++){
            for(y=0;y<m;y++){
                if(a[x][y]==1){
                    a[x][y]=0;
                    f(x,y);
                    cnt=cnt+1;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
/*
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
*/


