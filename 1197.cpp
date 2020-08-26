#include<stdio.h>
#include<algorithm>

using namespace std;

struct p{
    int a;
    int b;
    int c;
};

int v,e,i,a,b,c,j,par[10010]={0};
long long s=0;
p k[100010];


bool cmp(p x, p y){
    return x.c<y.c;
}

int fi(int x){
    if(x==par[x]){
        return x;
    }
    return par[x]=fi(par[x]);
}

void ui(int a,int b){
    par[a]=b;
}



int main(){
    scanf("%d %d",&v,&e);
    for(i=0;i<e;i++){
        scanf("%d %d %d",&k[i].a,&k[i].b,&k[i].c);
    }
    for(i=1;i<=v;i++){
        par[i]=i;
    }
    sort(k,k+e,cmp);
    for(i=0;i<e;i++){
        if(fi(k[i].a)!=fi(k[i].b)){
            s=s+k[i].c;
            ui(par[k[i].a],par[k[i].b]);
        }
    }
    printf("%lld",s);
}
