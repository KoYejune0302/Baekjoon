#include<stdio.h>
#include<string.h>

int main(){
    int n,i,t,s[50]={0};
    char a[50];
    scanf("%s",a);
    n=strlen(a);
    s[0]=1;
    s[1]=1;
    if(a[0]=='0'){
        printf("0");
        return 0;
    }
    for(i=1;i<n;i++){
        t=(a[i-1]-'0')*10+(a[i]-'0');
        if(t<=34 && t>=10){
            s[i+1]=s[i+1]+s[i-1];
        }
        if(a[i]!='0'){
            s[i+1]=s[i+1]+s[i];
        }
    }
    printf("%d",s[n]);
}
