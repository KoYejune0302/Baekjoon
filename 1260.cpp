#include<stdio.h>
#include<queue>

using namespace std;

int a[1010][1010]={0},b[1010]={0},n;

void dfs(int s){
    int i;
    for(i=1;i<=n;i++){
        if(a[s][i]==1 && b[i]==0){
            printf("%d ",i);
            b[i]=1;
            dfs(i);
        }
    }
}

int main(){
    int i,x,y,s,k,m;
    scanf("%d %d %d",&n,&m,&s);
    queue<int> bfs;
    for(i=0;i<m;i++){
        scanf("%d %d", &x,&y);
        a[x][y]=1;
        a[y][x]=1;
    }
    printf("%d ",s);
    b[s]=1;
    for(i=1;i<=n;i++){
        if(a[s][i]==1 && b[i]==0){
            printf("%d ",i);
            b[i]=1;
            dfs(i);
        }
    }
    for(i=0;i<1010;i++){
        b[i]=0;
    }
    b[s]=1;
    printf("\n");
    bfs.push(s);
    while(!bfs.empty()){
        k=bfs.front();
        bfs.pop();
        printf("%d ",k);
        for(i=1;i<=n;i++){
            if(a[k][i]==1 && b[i]==0){
                b[i]=1;
                bfs.push(i);
            }
        }
    }
}

/*
4 5 1
1 2
1 3
1 4
2 4
3 4
*/
