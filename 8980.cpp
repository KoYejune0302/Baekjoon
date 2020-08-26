#include<stdio.h>
#include<algorithm>

using namespace std;

struct box{
    int s;
    int f;
    int c;
};

bool cmp(const box &x,const box &y){
    if(x.f<y.f){
        return true;
    }
    else if(x.s>y.s){
        return x.f < y.f;
    }
    return false;
}

int main(){
    int n,m,k,i,j,t=0,s=0,a[10010]={0},ch;
    box b[10010];
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<k;i++){
        scanf("%d %d %d",&b[i].s,&b[i].f,&b[i].c);
    }
    sort(b,b+k,cmp);
    for(i=0;i<k;i++){
        t=b[i].c;
        for(j=b[i].s;j<b[i].f;j++){
            if(a[j]+b[i].c > m){
                t=min(t,m-a[j]);
            }
        }
        for(j=b[i].s;j<b[i].f;j++){
            a[j]=a[j]+t;
        }
        s=s+t;
    }
    printf("%d",s);
}

/*
4 40
6
3 4 20
1 2 10
1 3 20
1 4 30
2 3 10
2 4 20
*/
