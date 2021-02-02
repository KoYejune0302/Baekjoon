#include<bits/stdc++.h>
using namespace std;

int n,a[15]={},i,ch[2600010]={},sum=0,j;

int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    for(i=1;i<=n;i++){
        int b[15]={};
        for(j=i;j<n;j++){
            b[j]=1;
        }
        do{
            int t[15]={},k,t1=0;
            for(k=0;k<n;k++){
                if(b[k]==0){
                    t[t1]=a[k];
                    t1++;
                }
            }
            for(k=0;k<(1<<i-1);k++){
                int s=t[0],x;
                for(x=0;x<i-1;x++){
                    if((k>>x)&1) s+=t[x+1];
                    else s-=t[x+1];
                }
                ch[abs(s)]=1;
            }
        }while(next_permutation(b,b+n));
    }
    int cnt=0;
    for(i=1;i<=sum;i++){
        if(ch[i]==0) cnt++;
    }
    printf("%d",cnt);
}
