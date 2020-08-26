#include<stdio.h>
#include<algorithm>
#include<list>
#include<utility>

using namespace std;

list<pair<int,int> > a[1010];

int main(){
    int n,m,i,j,x,y,z,s[1010]={0},p,q;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back({y,z});
    }
    scanf("%d %d",&p,&q);
    for(i=0;i<=n;i++){
        s[i]=100000;
    }
    s[p]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(auto t : a[j]){
                s[t.first]=min(s[t.first],s[j]+t.second);
            }
        }
    }
    printf("%d",s[q]);
}
