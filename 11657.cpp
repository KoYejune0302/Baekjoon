#include<stdio.h>
#include<algorithm>
#include<list>
#include<utility>

using namespace std;

list<pair<int,int> > a[1010];

int main(){
    int n,m,i,j,x,y,z,s[1010]={0};
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back({y,z});
    }
    for(i=2;i<=n;i++){
        s[i]=10000000;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(auto t : a[j]){
                if(s[t.first]>s[j]+t.second && s[j]!=10000000){
                    s[t.first]=s[j]+t.second;
                    if(i==n){
                        printf("-1");
                        return 0;
                    }
                }
            }
        }
    }
    for(i=2;i<=n;i++){
        if(s[i]==10000000){
            s[i]=-1;
        }
        printf("%d\n",s[i]);
    }
}

