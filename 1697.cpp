#include<stdio.h>
#include<queue>
#include<utility>

using namespace std;

int main(){
    int  n,m,c[100010]={0};
    queue<pair<int, int> > q;
    scanf("%d %d",&n,&m);
    q.push({n,0});
    c[n]=1;
    while(1){
        auto t=q.front();
        if(t.first == m){
            printf("%d",t.second);
            break;
        }
        if(t.first-1>=0 && c[t.first-1]==0){
            q.push({t.first-1,t.second+1});
            c[t.first-1]=1;
        }
        if(t.first<m){
            if(c[t.first+1]==0){
                q.push({t.first+1,t.second+1});
                c[t.first+1]=1;
            }
            if(t.first*2 <= 100000 && c[t.first*2]==0){
                q.push({t.first*2,t.second+1});
                c[t.first*2]=1;
            }

        }
        q.pop();
    }
}
