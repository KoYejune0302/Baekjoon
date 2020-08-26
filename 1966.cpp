#include<stdio.h>
#include<queue>
#include<utility>


using namespace std;

int main(){
    int n,m,t,i,j,k,cnt;
    scanf("%d",&t);
    pair<int, int> a;
    for(i=0;i<t;i++){
        priority_queue<pair<int, int> > pq;
    	queue<pair<int, int> > q;
        scanf("%d",&n);
        scanf("%d",&m);
        for(j=0;j<n;j++){
            scanf("%d",&k);
            pq.push(make_pair(k, j));
            q.push(make_pair(k, j));
        }
        cnt = 1;
        while(1){
            if(pq.top().first == q.front().first){
                if(q.front().second == m){
                    break;
                }
                cnt=cnt+1;
                pq.pop();
                q.pop();
            }
            else{
                a=q.front();
                q.pop();
                q.push(a);
            }
        }
        printf("%d\n",cnt);
    }
}
