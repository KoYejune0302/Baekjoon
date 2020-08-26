#include<stdio.h>

int a[6][3]={0},ch=0;

void game(int x, int y){
    int i,j;
    if(x>=5 && y>=5){
        ch=1;
        for(i=0;i<6;i++){
            for(j=0;j<3;j++){
                if(a[i][j]!=0){
                    ch=0;
                }
            }
        }
    }
    if(x==y){
        game(x,y+1);
    }
    if(y>5 && x+1<=5){
        game(x+1,x+2);
    }
    if(a[x][0]>0 && a[y][2]>0){
        a[x][0]--;
        a[y][2]--;
        game(x,y+1);
        a[x][0]++;
        a[y][2]++;
    }
    if(a[x][1]>0 && a[y][1]>0){
        a[x][1]--;
        a[y][1]--;
        game(x,y+1);
        a[x][1]++;
        a[y][1]++;
    }
    if(a[x][2]>0 && a[y][0]>0){
        a[x][2]--;
        a[y][0]--;
        game(x,y+1);
        a[x][2]++;
        a[y][0]++;
    }
}

int main(){
    int i,j,k;
    for(int asf=0;asf<4;asf++){
        for(i=0;i<6;i++){
            for(j=0;j<3;j++){
                scanf("%d",&a[i][j]);
            }
        }
        ch=0;
        game(0,1);
        printf("%d ",ch);
    }
}
