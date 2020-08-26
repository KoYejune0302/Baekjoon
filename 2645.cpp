#include<stdio.h>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

struct qwe{
    int first;
    int second;
    int third;

    bool operator<(qwe z) const{
        return first<z.first;
    }
};

int main(){
    int n,a[55][55]={0},k,m,x1,y1,x2,y2,e,b[55][55]={0},r[4]={0,1,0,-1},c[4]={1,0,-1,0},ch[55][55]={0},i,j,h;
    pair<int, int> s,f,w[100];
    priority_queue<qwe> pq;
    qwe me[55][55];
    scanf("%d",&n);
    scanf("%d %d %d %d",&s.first,&s.second,&f.first,&f.second);
    scanf("%d",&k);
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&h);
        scanf("%d %d",&x1,&y1);
        for(j=1;j<h;j++){
            scanf("%d %d",&x2,&y2);
            if(x1==x2){
                for(e=min(y1,y2);e<=max(y1,y2);e++){
                    a[x1][e]=1;
                }
            }
            else{
                for(e=min(x1,x2);e<=max(x1,x2);e++){
                    a[e][y1]=1;
                }
            }
            x1=x2;
            y1=y2;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            b[i][j]=1e9;
        }
    }
    pq.push({-1,s.first,s.second});
    b[s.first][s.second]=1;
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        if(ch[t.second][t.third]==1){
            continue;
        }
        ch[t.second][t.third]=1;
        t.first=t.first*-1;
        if(t.second==f.first && t.third==f.second){
            break;
        }
        for(i=0;i<4;i++){
            if(t.second+r[i]>=1 && t.third+c[i]>=1 && t.second+r[i]<=n && t.third+c[i]<=n && ch[t.second+r[i]][t.third+c[i]]==0){
                b[t.second+r[i]][t.third+c[i]]=min(t.first+a[t.second+r[i]][t.third+c[i]]*(k-1)+1,b[t.second+r[i]][t.third+c[i]]);
                if(b[t.second+r[i]][t.third+c[i]]==t.first+a[t.second+r[i]][t.third+c[i]]*(k-1)+1){
                    me[t.second+r[i]][t.third+c[i]]={i,t.second,t.third};
                }
                pq.push({b[t.second+r[i]][t.third+c[i]]*-1,t.second+r[i],t.third+c[i]});
            }
        }
    }
    printf("%d\n",b[f.first][f.second]);
    int cnt=1;
    x1=f.first;
    y1=f.second;
    w[cnt]={x1,y1};
    me[s.first][s.second].first=-1;
    while(x1!=s.first || y1!=s.second){
        x2=me[x1][y1].second;
        y2=me[x1][y1].third;
        if(me[x1][y1].first!=me[x2][y2].first){
            cnt=cnt+1;
            w[cnt]={x2,y2};
        }
        x1=x2;
        y1=y2;
    }
    printf("%d ",cnt);
    for(i=cnt;i>=1;i--){
        printf("%d %d ",w[i].first,w[i].second);
    }
}
