#include<bits/stdc++.h>
using namespace std;

struct date{
    int a1;
    int a2;
    int b1;
    int b2;
};

bool cmp(){

}

int main(){
    int a[100010][5],n,i,m[13]={0,31,28,21,30,31,30,31,31,30,31,30,31};
    scanf("%f",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
        for(j=a[i][0];j<a[i][2];j++){
            a[i][4]+=m[j];
        }
        a[i][4]=a[i][3]-a[i][1];
    }
    sort(a,a+n,cmp);
}
