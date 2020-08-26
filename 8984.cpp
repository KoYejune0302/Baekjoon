#include<bits/stdc++.h>
using namespace std;

/*
long long n,l,a[100010][2],s[100010],up[100010],down[100010];

int main(){
    int i,j;
    scanf("%lld %lld",&n,&l);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&a[i][0],&a[i][1]);
        up[i]=i;
        down[i]=i;
    }
    sort(up,up+n,cmp1);
    sort()
    s[0]=l+abs(a[0][0]-a[0][1]);
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[j][0]==a[i][0] && a[j][1]<a[i][1]){
                s[i]=max(s[i],s[j]+l+abs(a[i][0]-a[i][1]));
            }
            else if(a[j][1]==a[i][1] && a[j][0]<a[i][0]){
                s[i]=max(s[i],s[j]+l+abs(a[i][0]-a[i][1]));
            }
            else{
                s[i]=max(s[i],l+abs(a[i][0]-a[i][1]));
            }
        }
    }
    printf("%lld %d",*max_element(s,s+n),max_element(s,s+n)-s);
}
*/
struct qwe{
    long long up;
    long long down;
    int num;
    bool operator<(const qwe z)const{
        if(up==z.up) return down<z.down;
        return up<z.up;
    }
};

bool cmp(qwe x,qwe y){
    return x.down < y.down;
}



long long i,j,b[2][100010],n,l;
long long dp[2][100010];
qwe a[100010];

int main(){
    scanf("%lld %lld",&n,&l);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&a[i].up,&a[i].down);

    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        a[i].num=i;
    }
    b[0][0]=1;
    for(i=1;i<n;i++){
        if(a[i].up==a[i-1].up){
            b[0][i]=b[0][i-1];
        }
        else{
            b[0][i]=b[0][i-1]+1;
        }
    }
    sort(a,a+n,cmp);
    b[1][a[0].num]=1;
    for(i=1;i<n;i++){
        if(a[i].down==a[i-1].down){
            b[1][a[i].num]=b[1][a[i-1].num];
        }
        else{
            b[1][a[i].num]=b[1][a[i-1].num]+1;
        }
    }
    sort(a,a+n);

    for(i=0;i<n;i++){
        long long k=a[i].num;
        long long t1=dp[0][b[0][k]],t2=dp[1][b[1][k]];
        dp[0][b[0][k]]=(long long)max(dp[0][b[0][k]],t2+abs(a[i].up-a[i].down)+l);
        dp[1][b[1][k]]=(long long)max(dp[1][b[1][k]],t1+abs(a[i].up-a[i].down)+l);
    }
    printf("%lld",max(*max_element(dp[0],dp[0]+n),*max_element(dp[1],dp[1]+n)));
}
