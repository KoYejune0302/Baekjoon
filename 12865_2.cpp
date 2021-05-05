#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[110];
int n,k,i,j,b[100010]={0};

int main(){
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    for(i=0;i<n;i++){
        for(j=k;j>=a[i].first;j--){
            b[j]=max(b[j],b[j-a[i].first]+a[i].second);
        }
    }
    printf("%d",b[k]);
}
