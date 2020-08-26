#include<stdio.h>
int tree[1000000],n,m;
int h_search(int s, int f){
    int i,h;
    long long sum=0;
    while(s<f){
        h=(s+f)/2+1;
        sum=0;
        for(i=0;i<n;i++){
            if(tree[i]>=h){
               sum=sum+(long long)(tree[i]-h);
            }
        }
        if(sum>=(long long)m){
            s=h;
        }
        else{
            f=h-1;
        }
    }
    return f;
}

int main(){
    int i;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++){
        scanf("%d",&tree[i]);
    }
	printf("%d",h_search(0,1000000000));
    return 0;
}

/*
입력예시
4 7
20 15 10 17
*/
