#include<stdio.h>
#include<algorithm>

using namespace std;

/*
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
*/

int main(){
    printf("%d",__gcd(1,1000000));
}
