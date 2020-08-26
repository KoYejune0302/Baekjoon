#include<stdio.h>
#include<algorithm>

using namespace std;

int s[1000010]={0},a[1000010]={0};

/*
int bi(int x,int y,int z){
    if(x==y){
        return x;
    }
    if(s[(x+y)/2]>=z){
        return bi(x,(x+y)/2,z);
    }
    return bi((x+y)/2+1,y,z);
}
*/


int main(){
    int n,i,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    s[0]=-1000000010;
    s[1]=a[1];
    m=1;
    for(i=2;i<=n;i++){
        if(a[i]>s[m]){
            m++;
            s[m]=a[i];
        }
        else{
            int t=lower_bound(s+1,s+m+1,a[i])-s;
            //t=bi(1,m,a[i]);
            s[t]=a[i];
        }
    }
    printf("%d",m);
}
