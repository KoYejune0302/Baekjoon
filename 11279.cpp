#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main(){
    int n,i,t;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        if(t==0 && pq.empty()){
            printf("0\n");
        }
        else if(t==0){
            printf("%d\n",pq.top());
            pq.pop();
        }
        else{
            pq.push(t);
        }
    }
}
