#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

int main(){
    char a[100010];
    stack<int> st;
    int s,i,cnt=0;
    scanf("%s", a);
    s=strlen(a);
    for(i=0;i<s;i++){
        if(a[i] == '(' && a[i+1] == ')'){
            cnt=cnt+st.size();
            i=i+1;
        }
        else if(a[i] == '('){
            st.push(1);
        }
        else{
            st.pop();
            cnt=cnt+1;
        }
    }
    printf("%d",cnt);
}

//()(((()())(())()))(())
