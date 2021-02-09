#include<bits/stdc++.h>
using namespace std;

int n,k,ch[30];
char a[50][20];

int main(){
    int i,j,mx=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(i=25;i>25-k;i--){
        ch[i]=1;
    }
    do{
        int cnt=0;
        if(ch[0]==1 && ch[2]==1 && ch[8]==1 && ch[13]==1 && ch[19]==1){
            for(i=0;i<n;i++){
                int t=0,l=strlen(a[i]);
                for(j=4;j<l-4;j++){
                    if(ch[a[i][j]-'a']!=1){
                        t=1;
                        break;
                    }
                }
                if(t==0){
                    cnt++;
                }
            }
            if(cnt>mx){
                mx=cnt;
            }
        }
    }while(next_permutation(ch,ch+26));
    printf("%d",mx);
}
