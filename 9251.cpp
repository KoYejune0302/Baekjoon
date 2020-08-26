#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char a[1010],b[1010];
int k[1010][1010];

int main(){
    int la,lb,i,j;
    scanf("%s",a+1);
    scanf("%s",b+1);
    la=strlen(a+1);
    lb=strlen(b+1);
    for(i=1;i<=la;i++){
        for(j=1;j<=lb;j++){
            if(a[i]==b[j]){
                k[i][j]=max(k[i-1][j-1]+1,k[i][j]);
            }
            k[i][j]=max(k[i][j-1],k[i][j]);
            k[i][j]=max(k[i-1][j],k[i][j]);
        }
    }
    printf("%d",k[la][lb]);
}
