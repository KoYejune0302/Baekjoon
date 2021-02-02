#include<bits/stdc++.h>
using namespace std;

int b[10010],n,m;
pair<int, int> a[60];

bool cmp(pair<int, int> x,pair<int, int> y){
    return x.first > y.first;
}


int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i].first);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    sort(b,b+m,greater<int>());
    sort(a,a+n,cmp);
    if(b[0]>a[0].first){
        printf("-1");
        return 0;
    }
    for(i=1;i<=m;i++){
        int cnt=0;
        for(j=0;j<n;j++){
            if(i*j>m){
                break;
            }
            if(b[i*j]>a[j].first){
                cnt=-1;
                break;
            }
        }
        if(cnt==-1) continue;
        if(i*n>=m){
            printf("%d",i);
            return 0;
        }
    }
}
