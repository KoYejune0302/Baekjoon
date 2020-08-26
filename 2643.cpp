#include<stdio.h>
#include<algorithm>
#include<utility>

using namespace std;

int n,k[110][110]={0};
pair<int, int> a[110];

bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first!=y.first){
            return x.first>y.first;
    }
    return x.second>y.second;
}

int main(){
    int i,j,m=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    for(i=1;i<=n;i++){
        if(a[i].first>a[i].second){
            swap(a[i].first,a[i].second);
        }
    }
    sort(a+1,a+n+1,cmp);
    k[1][1]=1;
    for(i=2;i<=n;i++){
        for(j=1;j<=n;j++){
            k[i][j]=k[i-1][j];
        }
        for(j=1;j<=i;j++){
            if(a[i].first<=a[j].first && a[i].second<=a[j].second){
                k[i][i]=max(k[i-1][j]+1,k[i][i]);
            }
        }
    }
    for(i=1;i<=n;i++){
        m=max(m,k[n][i]);
    }
    printf("\n\n");
    for(i=1;i<=n;i++){
        printf("%d %d\n",a[i].first,a[i].second);
    }
    printf("\n\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%2d",k[i][j]);
        }
        printf("\n");
    }
    printf("%d",m);
}

