#include<stdio.h>

int n,m,a[110][2]={0},k[110][10010]={0};

int main(){
    int i,j,p;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    k[0][0]=1;
    for(i=1;i<=m;i++){
        for(p=0;p<=n;p++){
            k[i][p]=k[i-1][p];
        }
        for(j=1;j<=a[i][1];j++){
            for(p=0;p<=n;p++){
                if(k[i-1][p]!=0){
                    if(p+a[i][0]*j<=n){
                        k[i][p+a[i][0]*j]=k[i][p+a[i][0]*j]+k[i-1][p];
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        printf("%d : %d \n",i,k[m][i]);
    }
    printf("%d",k[m][n]);
}

/*
20
3
5 3
10 2
1 5
*/
/*
4
*/
