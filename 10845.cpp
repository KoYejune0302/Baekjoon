#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int main(){
    int n,i,s;
    char text[10];
    queue<int>  q;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s", text);
        if(!strcmp(text,"push")){
            scanf("%d",&s);
            q.push(s);
        }
        else if(!strcmp(text,"pop")){
            if(q.empty()){
                printf("-1");
            }
            else{
                printf("%d",q.front());
                q.pop();
            }
        }
        else if(!strcmp(text,"size")){
            printf("%d",q.size());
        }
        else if(!strcmp(text,"empty")){
            printf("%d",(q.empty()?1:0));
        }
        else if(!strcmp(text,"front")){
            if(q.empty()){
                printf("-1");
            }
            else{
                printf("%d",q.front());
            }
        }
        else if(!strcmp(text,"back")){
            if(q.empty()){
                printf("-1");
            }
            else{
                printf("%d",q.back());
            }
        }
    }
    return 0;
}

