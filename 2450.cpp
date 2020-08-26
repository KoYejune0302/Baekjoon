#include<bits/stdc++.h>
using namespace std;

int n,a[4],b[100010],c[100010],i,j,k,mi,q[3]={1,2,3};
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
        a[b[i]]++;
    }
    mi=n;
    do{
        int t=0,e[4][4]={0};
        for(i=0;i<3;i++){
            for(j=0;j<a[q[i]];j++){
                c[t+j]=q[i];
            }
            t=t+a[q[i]];
        }
        for(i=0;i<n;i++){
            if(b[i]!=c[i]){
                e[b[i]][c[i]]++;
            }
        }
        int cnt=e[2][1]+e[3][1];
        if(e[1][2]<e[2][1]){
            cnt=cnt+e[3][2];
        }
        else{
            cnt=cnt+e[2][3];
        }
        mi=min(mi,cnt);
    }while(next_permutation(q,q+3));
    printf("%d",mi);
}
