#include<bits/stdc++.h>
using namespace std;

int n,r,c,a,b,k[2][2]={0,1,2,3},s=0;

int f(int n, int x, int y){
    int m;
    if(n==0) return 0;
    m=(int)pow(2,n-1);
    return k[x/m][y/m]*(int)pow(m,2)+f(n-1,x%m,y%m);
}

int main(){
    scanf("%d %d %d",&n,&r,&c);
    printf("%d",f(n,r,c));
    return 0;
}
