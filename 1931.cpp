#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y){
    if(x.second == y.second){
        return x.first < y.first;
    }
    else{
        return x.second < y.second;
    }
}

int main(){
    int n,i,cnt,s;
    pair<int, int> a[100010];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a,a+n,cmp);
    s=0;
    cnt=1;
    for(i=1;i<n;i++){
        if(a[i].first>=a[s].second){
          cnt++;
          s=i;
        }
    }
    printf("%d",cnt);
}
