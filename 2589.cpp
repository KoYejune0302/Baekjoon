#include<stdio.h>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int n,m;
char a[55][55];

int bfs(int x, int y){
    int s=0,i,j,b[55][55]={},r[4]={-1,0,1,0},c[4]={0,1,0,-1};
    queue<pair<int, int> > q;
    q.push({x, y});
    b[x][y]=1;
    while(!q.empty()){
        auto k=q.front();
        for(i=0;i<4;i++){
            if( k.first+r[i]>=0 && k.first+r[i] <n && k.second+c[i]>=0 &&
                k.second+c[i]<m && a[k.first+r[i]][k.second+c[i]]=='L' &&
                b[k.first+r[i]][k.second+c[i]]==0){

                b[k.first+r[i]][k.second+c[i]]=b[k.first][k.second]+1;
                q.push({k.first+r[i], k.second+c[i]});
            }
        }
        q.pop();
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
           s=max(s,b[i][j]);
        }
    }
    return s;
}

int main(){
    int i,j,s=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++){
       for(j=0;j<m;j++){
            if(a[i][j]=='L'){
                s=max(s, bfs(i,j));
            }
        }
    }
    printf("%d",s-1);
    return 0;
}
/*
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW
*/
