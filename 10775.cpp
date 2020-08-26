#include<stdio.h>

int g,p,i,x,c=0,par[100010]={0};

int fi(int x){
    if(x==par[x]){
        return x;
    }
    return par[x]=fi(par[x]);
}

int main(){
    scanf("%d %d",&g,&p);
    for(i=1;i<=g;i++){
        par[i]=i;
    }
    for(i=0;i<p;i++){
        scanf("%d",&x);
        if(fi(x)!=0){
            c++;
            par[fi(x)]=fi(x)-1;
        }
        else{
            break;
        }
    }
    printf("%d",c);
}
