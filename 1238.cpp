#include<stdio.h>
#include<algorithm>
#include<queue>
#include<list>
#include<utility>

using namespace std;

int n,m,x;
int i,j,t1,t2,t3,v[1010]={0},c[2][1010]={0},s=0;
priority_queue<pair<int, int> > q;
list<pair<int, int> > a[2][1010];

int main(){
    scanf("%d %d %d",&n,&m,&x);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&t1,&t2,&t3);
        a[0][t1].push_back({t2,t3});
        a[1][t2].push_back({t1,t3});
    }
    for(i=0;i<2;i++){
        for(j=1;j<=n;j++){
                c[i][j]=1000000;
        }
        q.push({0,x});
        c[i][x]=0;
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            t.first=t.first*-1;
            if(v[t.second]==1){
                continue;
            }
            v[t.second]=1;
            for(auto j: a[i][t.second]){
                c[i][j.first]=min(c[i][j.first],c[i][t.second]+j.second);
                q.push({c[i][j.first]*-1,j.first});
            }
        }
        for(j=1;j<=n;j++){
            v[j]=0;
        }
    }
    for(i=1;i<=n;i++){
        s=max(s,c[0][i]+c[1][i]);
    }
    printf("%d",s);
}
