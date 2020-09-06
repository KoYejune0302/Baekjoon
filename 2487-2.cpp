#include<bits/stdc++.h>
using namespace std;

int n,a[20010],b[20010],c[20010],d[20010],s=1;
queue<int> q;

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    for(i=1;i<=n;i++){
        c[i]=i;
        d[i]=1;
    }
    for(i=1;i<=n;i++){
        if(d[i]==1){
            while(a[i]!=c[i]){
                q.push(c[i]);
                c[i]=b[c[i]];
                d[i]++;
            }
            while(!q.empty()){
                d[q.front()]=d[i];
                q.pop();
            }
        }
    }
    for(i=1;i<=n;i++){
        int temp = __gcd(s,d[i]);
        s= temp*(s/temp)*(d[i]/temp);
    }
    printf("%d",s);
}
