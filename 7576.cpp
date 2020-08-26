#include<stdio.h>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int a[1010][1010],n,m,cnt,b[100][100];
queue<pair<int, int> > q;

void bfs(){
    int i,r[4]={-1,0,1,0},c[4]={0,1,0,-1};
    while(!q.empty()){
        auto k=q.front();
        for(i=0;i<4;i++){
            if(k.first+r[i]>=0 && k.first+r[i] <n && k.second+c[i]>=0 &&
                k.second+c[i]<m && a[k.first+r[i]][k.second+c[i]]==0 &&
                b[k.first+r[i]][k.second+c[i]]==0){

                b[k.first+r[i]][k.second+c[i]]=b[k.first][k.second]+1;
                q.push({k.first+r[i], k.second+c[i]});
            }
        }
        q.pop();
    }
}

int main(){
    int i,j,mx=0,c;
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    c=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==0){
                c=1;
            }
        }
    }
    if(c==0){
        printf("0");
        return 0;
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==1){
                q.push({i,j});
                b[i][j]=1;
            }
        }
    }
    bfs();

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b[i][j]==0 && a[i][j]!=-1){
                printf("-1");
                return 0;
            }
            else{
                mx=max(mx, b[i][j]);
            }
        }
    }
    printf("%d",mx-1);
}

/*
6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1
*/
