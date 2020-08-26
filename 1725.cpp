#include<stdio.h>
#include<stack>
#include<utility>

using namespace std;

int main(){
    int n,i,m=-10,k,s=1;
    stack<pair<int, int> > a;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &k);
        s=i;
        while(!a.empty() && a.top().second > k){
            if(m<(i-a.top().first)*a.top().second){
                m=(i-a.top().first)*a.top().second;
                printf("max : %dX%d\n",i-a.top().first, a.top().second);
            }
            s=a.top().first;
            printf("pop :%d %d\n",a.top().first,a.top().second);
            a.pop();
        }
        if(a.empty() || a.top().second<k){
            a.push({s,k});
            printf("push :%d %d\n",s,k);
        }
    }
    i=n+1;
    while(!a.empty()){
        if(m<(i-a.top().first)*a.top().second){
            m=(i-a.top().first)*a.top().second;
        }
        a.pop();
    }
    printf("%d", m);
    return 0;
}
/*
7
2
1
4
5
1
3
3
*/
