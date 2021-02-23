#include<bits/stdc++.h>
using namespace std;

int n,a[2500][2500],s[3];

void f(int x1,int y1,int x2,int y2){
    int i,j,ch=0;
    if(x1==x2 && y1==y2){
        s[a[x1][y1]+1]++;
        return;
    }
    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            if(a[i][j]!=a[x1][y1]){
                ch=1;
                break;
            }
        }
    }
    if(ch==0){
        s[a[x1][y1]+1]++;
        return;
    }
    int m=(x2-x1+1)/3;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            f(x1+i*m,y1+j*m,x1+i*m+m-1,y1+j*m+m-1);
        }
    }
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    f(0,0,n-1,n-1);
    printf("%d\n%d\n%d\n",s[0],s[1],s[2]);
    return 0;
}
