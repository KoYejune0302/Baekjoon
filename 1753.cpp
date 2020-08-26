#include<stdio.h>
#include<queue>
#include<algorithm>
#include<list>

using namespace std;

struct p{
    int first;
    int second;
    bool operator<(const p a)const{
        return first>a.first;
    }
};

int n,m,k,u,v,w,i,j,b[20010]={0},c[20010]={0};
priority_queue<p> q;
p t;
list<p> a[20010];

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back({v,w});
    }
    for(i=1;i<=n;i++){
        c[i]=200000;
    }
    q.push({0,k});
    c[k]=0;
    while(!q.empty()){
        t=q.top();
        q.pop();
        if(b[t.second]!=1){
            b[t.second]=1;
            for(auto j : a[t.second]){
                if(b[j.first]==0){
                    c[j.first]=min(c[t.second]+j.second,c[j.first]);
                    q.push({c[j.first],j.first});
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        if(c[i]!=200000){
            printf("%d\n",c[i]);
        }
        else{
            printf("INF\n");
        }
    }
}
