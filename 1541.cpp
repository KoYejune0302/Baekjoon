#include<stdio.h>
#include<string.h>
#include<math.h>

char a[60];

int num(int cnt, int i){
    int j, t1=0;
    for(j=0;j<cnt;j++){
        t1=t1+(a[i-j-1]-48)*(int)pow(10,j);
    }
    return t1;

}

int main(){
    int n,i,j,s=0,cnt=0,t1=0,k;
    scanf("%s",a);
    n=strlen(a);
    a[n]='+';
    n=n+1;
    for(i=0;i<n;i++){
        if(a[i]=='+'){
            s=s+num(cnt, i);
            cnt=0;
        }
        else if(a[i]=='-'){
            s=s+num(cnt, i);
            cnt=0;
            break;
        }
        else{
            cnt=cnt+1;
        }
    }
    for(k=i+1;k<n;k++){
        if(a[k]=='-' || a[k]=='+'){
            s=s-num(cnt, k);
            cnt=0;
        }
        else{
            cnt=cnt+1;
        }
    }
    printf("%d",s);
}
