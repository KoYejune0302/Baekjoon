#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

int main(){
    stack<int> s;
    int n,i,w;
    char text[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
            scanf("%s",&text);
            if(!strcmp(text,"push")){
                    scanf("%d",&w);
                    s.push(w);
            }
            else if(!strcmp(text,"pop")){
                     if(s.empty()){
                        printf("-1\n");
                    }
                    else{
                        printf("%d\n",s.top());
                        s.pop();
                    }
            }
            else if(!strcmp(text,"size")){
                    printf("%d\n",s.size());
            }
            else if(!strcmp(text,"empty")){
                    printf("%d\n",s.empty()?1:0);
            }
            else if(!strcmp(text,"top")){
                    if(s.empty()){
                        printf("-1\n");
                    }
                    else{
                        printf("%d\n",s.top());
                    }
            }
    }
}
/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
