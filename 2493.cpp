#include<stdio.h>
#include<stack>
#include<utility>

using namespace std;

int main(){
    int n,i,k;
    stack<pair<int, int> > t;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &k);

        while(!t.empty() && t.top().second<=k){
            t.pop();
        }

        if(t.empty()){
            printf("0 ");
        }
        else{
            printf("%d ", t.top().first);
        }
        t.push({i,k});
    }
    return 0;
}

/*
5
6 9 5 7 4
*/
