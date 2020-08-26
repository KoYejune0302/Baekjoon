#include<stdio.h>
#include<algorithm>

using namespace std;

struct date{
    int s1;
    int s2;
    int f1;
    int f2;
};

bool f(int x1, int x2,int y1, int y2){
    if(x1!=y1){
        return x1<y1;
    }
    else{
        return x2<=y2;
    }
}

bool cmp(date x, date y){
    if(x.s1==y.s1 && x.s2 == y.s2){
        return !f(x.f1,x.f2,y.f1,y.f2);
    }
    else{
        return f(x.s1,x.s2,y.s1,y.s2);
    }
}

date a[100010];

int main(){
    int n,i,t,cnt,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
       scanf("%d %d %d %d",&a[i].s1,&a[i].s2,&a[i].f1,&a[i].f2);
    }
    a[0]={3,1,3,1};
    sort(a+1,a+n+1,cmp);
    t=0;
    i=1;
    cnt=0;
    j=1;
    while(f(a[t].f1,a[t].f2,11,30)){
        k=0;
        for(;j<=n;j++){
            if(f(a[j].s1,a[j].s2,a[t].f1,a[t].f2) && f(a[k].f1,a[k].f2,a[j].f1,a[j].f2)){
                k=j;
            }
            else if(!f(a[j].s1,a[j].s2,a[t].f1,a[t].f2)){
                break;
            }
        }
        t=k;
        if(k==0){
            printf("0");
            return 0;
        }
        cnt=cnt+1;
    }
    printf("%d",cnt);
}
