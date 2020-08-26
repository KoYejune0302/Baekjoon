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
push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/
