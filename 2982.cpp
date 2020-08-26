#include<stdio.h>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

int a,b,k,g1,g[1010],s[1010],u,v,l,n,m,t,i,j,c[1010][1010];
pair<int,int> d[1010][1010];
priority_queue<pair<int, int> > q;

int main(){
    int vi[1010]={0};
    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&a,&b,&k,&g1);
    for(i=1;i<=g1;i++){
        scanf("%d",&g[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&l);
        c[u][v]=l;
        c[v][u]=l;
    }
    t=0;
    for(i=1;i<g1;i++){
        d[g[i]][g[i+1]].first=t;
        d[g[i+1]][g[i]].first=t;
        t=t+c[g[i]][g[i+1]];
        d[g[i]][g[i+1]].second=t;
        d[g[i+1]][g[i]].second=t;
    }
    for(i=0;i<=n;i++){
        s[i]=1000000;
    }
    s[a]=k;
    q.push({k,a});
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        t.first=t.first*-1;
        if(vi[t.second]==1){
            continue;
        }
        vi[t.second]=1;
        for(i=1;i<=n;i++){
            if(c[t.second][i]==0){
                continue;
            }
            if(vi[i]==0){
                int ti=s[t.second]+c[t.second][i];
                if(s[t.second]<d[t.second][i].second && s[t.second]>=d[t.second][i].first){
                    ti=d[t.second][i].second+c[t.second][i];
                }
                s[i]=min(s[i],ti);
                q.push({s[i]*-1,i});
            }
        }
    }
    printf("%d",s[b]-k);
}
