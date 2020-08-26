#include<stdio.h>
#include<algorithm>

using namespace std;

bool cmp(int x, int y){
    return x>y;
}

int main(){
    int a[100010],n,i,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    for(i=0;i<n;i++){
        s = max(s, a[i]*(i+1));
    }
    printf("%d",s);
}
