#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int> mx;
int main(){
    int a,b,ch=0;
    scanf("%d %d",&n,&m);
    a=n;
    b=n;
    m=m/n;
    mx.first=INT_MAX;
    mx.second=1;
    for(int i=2; i*i<=m;i++){
        if(m%i==0 && __gcd(i,(m/i))==1){
            mx.first=min(mx.first,a*i+b*(m/i));
            if(mx.first==a*i+b*(m/i)){
                mx.second=i;
            }
        }
    }
    a=a*mx.second;
    b=b*(m/mx.second);
    printf("%d %d",min(a,b),max(a,b));
}
