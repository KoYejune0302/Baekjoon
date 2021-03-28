#include<bits/stdc++.h>
using namespace std;

int f(int a,int b){
    int i=0,s=1;
    for(i=1;i<=b;i++){
        s=s*a;
    }
    return s;
}

int main(){
    char t[40];
    int a=0,b=0,l,i,sum=0;
    scanf("%s",t);
    l=strlen(t);
    //printf("%s %d\n",t,l);
    for(i=0;i<l;i++){
        if(t[i]=='('){
            a++;
            //printf("%d\n",1);
        }
        else if(t[i]==')'){
            a--;
            if(a<0){
                printf("0");
                return 0;
            }
            if(i>=1 && t[i-1]=='('){
                sum=sum+2*f(2,a)*f(3,b);
                //printf("a : %d  b : %d sum : %d\n",a,b,sum);
            }
            //printf("%d\n",2);
        }
        else if(t[i]=='['){
            b++;
            //printf("%d\n",3);
        }
        else if(t[i]==']'){
            b--;
            if(b<0){
                printf("0");
                return 0;
            }
            if(i>=1 && t[i-1]=='['){
                sum=sum+3*f(2,a)*f(3,b);
                //printf("a : %d  b : %d sum : %d\n",a,b,sum);
            }
            //printf("%d\n",4);
        }
    }
    if(a==0 && b==0){
        printf("%d",sum);
    }
    else{
        printf("0");
    }
}
