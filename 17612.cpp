#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

struct m{
    int x;
    int y;
    bool operator<(const m a)const{
        if(x!=a.x){
            return x>a.x;
        }
        return y>a.y;
    }
};

struct z{
    int a;
    int b;
    int c;
};

bool cmp(const z x,const z y){
    if(x.b!=y.b){
        return x.b<y.b;
    }
    return x.c>y.c;

}

int n,k,a[100010][2],t=1,b[10010]={0};
z p[100010];
long long s=0;
priority_queue<m> q;


int main(){
    int i;
    m h;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(i=1;i<=k;i++){
        q.push({0,i});
    }
    for(i=1;i<=n;i++){
        h=q.top();
        q.pop();
        h.x=h.x+a[i][1];
        q.push(h);
        p[t].a=a[i][0];
        p[t].b=h.x;
        p[t].c=h.y;
        t++;
    }
    sort(p+1,p+n+1,cmp);
    for(i=1;i<=n;i++){
        s=s+(long long)p[i].a*i;
    }
    printf("%lld",s);
}
