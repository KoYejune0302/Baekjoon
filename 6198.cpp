#include<stdio.h>
#include<stack>

using namespace std;

int main(){
    int n,i,k;
    long long cnt=0;
    stack<int> t;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &k);
        while(!t.empty() && t.top()<=k){
            t.pop();
        }
        cnt =cnt+t.size();
        t.push(k);
    }
    printf("%lld",cnt);
}
/*
6
10
3
7
4
12
2
*/
