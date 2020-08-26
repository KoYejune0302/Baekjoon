#include<stdio.h>
#include<list>

using namespace std;

int a,b,i,u,v,n,m,x,ch[100010]={0};
list<int> p[100010],q[100010];

int f(int h,list<int> t[]){
    int cnt=1;
    for(auto i:t[h]){
        if(ch[i]==1){
            continue;
        }
        cnt=cnt+f(i,t);
        ch[i]=1;
    }
    return cnt;
}


int main(){
    scanf("%d %d %d",&n,&m,&x);
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        p[b].push_back(a);
        q[a].push_back(b);
    }
    ch[x]=0;
    u=f(x,p);
    for(i=1;i<=n;i++){
        ch[i]=0;
    }
    v=f(x,q);
    printf("%d %d",u,n-v+1);
}

