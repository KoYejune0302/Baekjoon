#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int n,k,a[110]={0},c,cnt=0,b[110]={0},d[110]={0},x,p,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        d[i]=200;
    }
    for(i=0;i<k;i++){
        c=0;
        for(j=0;j<n;j++){
            if(a[i]==b[j]){
                c=1;
                break;
            }
            else if(b[j]==0){
                b[j]=a[i];
                c=1;
                break;
            }
        }
        if(c==0){
            for(j=i+1;j<k;j++){
                for(p=0;p<n;p++){
                    if(a[j]==b[p]){
                        d[p]=min(d[p],j);
                        break;
                    }
                }
            }
            x=0;
            for(j=1;j<n;j++){
                if(d[x]<d[j]){
                   x=j;
                }
            }
            b[x]=a[i];
            cnt=cnt+1;
            for(j=0;j<n;j++){
                d[j]=200;
            }
        }
    }
    printf("%d",cnt);
}
