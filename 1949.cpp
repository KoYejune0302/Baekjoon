#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
    int n,m,cnt,i,j,k,ch=100001;
    pair<int, int> a[100100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d %d",&a[j].first,&a[j].second);
        }
        sort(a,a+m);
        cnt=0;
        ch=100001;
        for(j=0;j<m;j++){
            ch = min(a[j].second, ch);
            if(ch == a[j].second){
                cnt=cnt+1;
            }
        }
        printf("%d\n",cnt);
    }
}
