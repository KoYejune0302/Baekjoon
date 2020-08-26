#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int i,j,k,l,b[510][510];
char a[510];

int main(){
    scanf("%s",a);
    l=strlen(a);
    for(i=1;i<l;i++){
        for(j=0;j<l-i;j++){
            if((a[j]=='a' && a[j+i]=='t') || (a[j]=='g' && a[j+i]=='c')){
                if(j+1==j+i){
                    b[j][j+i]=2;
                }
                else{
                    b[j][j+i]= max(b[j+1][j+i-1]+2,b[j][j+i]);
                }
            }
            for(k=j;k<=j+i;k++){
                b[j][j+i]=max(b[j][j+i],b[j][k]+b[k][j+i]);
            }
        }
    }

    printf("%d",b[0][l-1]);
}
