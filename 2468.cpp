#include<stdio.h>

int a[110][110],b[110][110],n,h;

void f(int x, int y){
    int r[4]={-1,0,1,0},c[4]={0,1,0,-1},i;
    for(i=0;i<4;i++){
        if(y+c[i]<n && y+c[i] >=0 && x+r[i]<n && x+r[i] >=0 && a[x+r[i]][y+c[i]]>h && b[x+r[i]][y+c[i]]==0){
            b[x+r[i]][y+c[i]]=1;
            f(x+r[i],y+c[i]);
        }
    }
}

int main(){
    int m=0,p,q,s=1,cnt,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]>m){
                m=a[i][j];
            }
        }
    }
    for(h=1;h<=m;h++){
        cnt=0;
        for(p=0;p<n;p++){
            for(q=0;q<n;q++){
                if(a[p][q]>h && b[p][q]==0){
                    b[p][q]=1;
                    f(p,q);
                    cnt=cnt+1;
                }
            }
        }
        if(cnt>s){
            s=cnt;
        }
        for(p=0;p<n;p++){
            for(q=0;q<n;q++){
                b[p][q]=0;
            }
        }
    }
    printf("%d",s);
    return 0;
}
