#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

struct p{
    int c;
    int x;
    int y;
    bool operator<(const p a)const{
        return c>a.c;
    }
};

int n,a[200][200]={0},b[200][200],r[4]={0,1,0,-1},c[4]={1,0,-1,0},v[200][200]={0};
priority_queue<p> q;

int main(){
    int i,j,cnt=1;
    while(true){
        scanf("%d",&n);
        if(n==0){
            return 0;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                b[i][j]=150000;
            }
        }
        q.push({a[0][0],0,0});
        b[0][0]=a[0][0];
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            if(v[t.x][t.y]==0){
                v[t.x][t.y]=1;
                for(i=0;i<4;i++){
                    if(t.x+r[i]<n && t.y+c[i]<n && t.x+r[i]>=0 && t.y+c[i]>=0){
                        b[t.x+r[i]][t.y+c[i]]=min(b[t.x+r[i]][t.y+c[i]],b[t.x][t.y]+a[t.x+r[i]][t.y+c[i]]);
                        q.push({b[t.x+r[i]][t.y+c[i]],t.x+r[i],t.y+c[i]});
                    }
                }
            }
        }
        printf("Problem %d: %d\n",cnt,b[n-1][n-1]);
        cnt++;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                v[i][j]=0;
            }
        }

    }
}
