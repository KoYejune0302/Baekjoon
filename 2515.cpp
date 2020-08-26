#include<stdio.h>
#include<algorithm>
#include<utility>

using namespace std;

int n,s,p[300010];
pair<int,int> a[300010];

int main(){
    int i,j,m;
    scanf("%d %d",&n,&s);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1);
    p[0]=0;
    int t=0;
    for(i=1;i<=n;i++){
        while(a[i].first-a[t].first>=s){
            t++;
        }
        p[i]=max(p[i-1],a[i].second+p[t-1]);
    }
    printf("%d",p[n]);
}
