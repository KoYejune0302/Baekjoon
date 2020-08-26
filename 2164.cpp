#include<stdio.h>
#include<queue>

using namespace std;

int main(){
    int n,i;
    queue<int> number;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        number.push(i);
    }
    while(number.size()!=1){
        number.pop();
        number.push(number.front());
        number.pop();
    }
    printf("%d",number.front());
}
