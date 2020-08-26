#include<stdio.h>

int n,m,par[1000010];

int fi(int x){
    if(x==par[x]){
        return x;
    }
    return par[x]=fi(par[x]);
}

void un(int a,int b){
    par[fi(a)]=fi(b);
}

int main(){
    int a,b,c,i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        par[i]=i;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&c,&a,&b);
        if(c==0){
            un(a,b);
        }
        else{
            if(fi(a)==fi(b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}
