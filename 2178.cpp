#include<stdio.h>
#include<queue>
#include<utility>

using namespace std;

int main(){
    int x,y,a[110][110]={0},i,j,r[4]={-1,0,1,0},c[4]={0,1,0,-1},b[110][110]={0},s[110][110]={0};
    queue<pair<int, int> > q;
    scanf("%d %d",&x,&y);
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    q.push({1, 1});
    b[1][1]=0;
    s[1][1]=1;
    while(!q.empty()){
        auto k=q.front();
        printf("%d %d\n",k.first,k.second);
        if(k.first == x && k.second == y){
            printf("%d",s[k.first][k.second]);
            break;
        }
        for(i=0;i<4;i++){
            if( k.first+r[i]>0 && k.first+r[i] <=x && k.second+c[i]>0 &&
               k.second+c[i]<=y && a[k.first+r[i]][k.second+c[i]]==1 &&
               b[k.first+r[i]][k.second+c[i]]==0){

                b[k.first+r[i]][k.second+c[i]]=1;
                q.push({k.first+r[i], k.second+c[i]});
                s[k.first+r[i]][k.second+c[i]]=s[k.first][k.second]+1;
            }
        }
        q.pop();
    }
}

/*
4 6
101111
101010
101011
111011
*/
