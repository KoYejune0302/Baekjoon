#include<bits/stdc++.h>
using namespace std;


int m,n,l,t,a[100010]={0},k[100010][2]={0};

void solve1(){
    int i,cnt=0;

    scanf("%d %d %d",&m,&n,&l);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&k[i][0],&k[i][1]);
    }
    sort(a,a+m);
    for(i=0;i<n;i++){
        t=lower_bound(a,a+m,k[i][0])-a;
        if(t==m){
            if(k[i][0]-a[t-1]+k[i][1]<=l){
                cnt++;
            }
            continue;
        }
        if(a[t]-k[i][0]+k[i][1]<=l){
            cnt++;
        }
        else if(t-1>=0 && k[i][0]-a[t-1]+k[i][1]<=l){
            cnt++;
        }
    }
    printf("%d",cnt);
}

/*
int solve2(){
    int i,j,cnt=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(abs(k[i][0]-a[j])+k[i][1]<=l){
                cnt++;
            }
        }
    }
    return cnt;
    //printf("sol2 %d",cnt);
}
*/

int main(){
    int i;
    /*
    srand(time(NULL));
    m=5;
    n=10;
    l=10;
    while(1){
        for(i=0;i<m;i++){
            a[i]=rand()%100;
        }
        for(i=0;i<n;i++){
            k[i][0]=rand()%100;
            k[i][1]=rand()%100;
        }
        if(solve2() != solve1()){
            for(i=0;i<m;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
            for(i=0;i<n;i++){
                printf("%d %d \n",k[i][0],k[i][1]);
            }
            printf("sol1 %d sol2 %d",solve1(),solve2());
            break;
        }
    }
    */
    solve1();
    return 0;
}
