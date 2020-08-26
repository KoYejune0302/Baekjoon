#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

char a[1010],b[1010];
int k[1010][1010];

int main(){
    int i,j,la,lb;
    scanf("%s",a+1);
    scanf("%s",b+1);
    la=strlen(a+1);
    lb=strlen(b+1);
    for(i=1;i<=la;i++){
        for(j=1;j<=lb;j++){
            k[i][j]=1000;
        }
    }
    for(i=1;i<=max(la,lb);i++){
        k[0][i]=i;
        k[i][0]=i;
    }
    for(i=1;i<=la;i++){
        for(j=1;j<=lb;j++){
            if(a[i]==b[j]){
                k[i][j]=min(k[i][j],k[i-1][j-1]);
            }
            else{
                k[i][j]=min(k[i][j],k[i-1][j-1]+1);
                k[i][j]=min(k[i][j],k[i-1][j]+1);
                k[i][j]=min(k[i][j],k[i][j-1]+1);
            }
        }
    }
    for(i=1;i<=la;i++){
        for(j=1;j<=lb;j++){
            printf("%2d",k[i][j]);
        }
        printf("\n");
    }
    printf("%d",k[la][lb]);
}
