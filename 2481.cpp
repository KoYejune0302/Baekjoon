#include<stdio.h>
#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

list<int> a[100010];
int n,k,m,i,j,p,cnt,c[100010][2],ch[100010],r;
pair<int, int> b[100010];
priority_queue<pair<int,int> > q;

/*
int fi(int x,int y,string s){
    if(b[(x+y)/2].first==s){
        return b[(x+y)/2].second;
    }
    if(x==y){
        return -1;
    }
    if(b[(x+y)/2].first>s){
        return fi(x,(x+y)/2,s);
    }
    return fi((x+y)/2+1,y,s);
}
*/

int main(){
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        string s;
        cin >> s;
        for(j=0;j<k;j++){
            b[i].first=2*b[i].first+(s[j]-'0');
        }
        b[i].second=i;
    }
    sort(b+1,b+n+1);
    /*
    for(i=1;i<=n;i++){
        int w=1;
        for(j=0;j<k;j++){
            string st=b[i].first;
            st[j]=(((b[i].first[j]-'0')+1)%2)+'0';
            int d=fi(w,n,st);
            if(d!=-1){
                a[i].push_back(d);
                w=d;
            }
        }
    }
    */


    for(i=1;i<=n;i++){
        for(j=0;j<k;j++){
            int st = b[i].first ^ (1<<j);
            auto tmp = lower_bound(b+1,b+n+1,make_pair(st,0));
            if(tmp!=b+n+1 && tmp -> first == st){
                a[b[i].second].push_back(tmp-> second);
            }
        }
    }

    for(i=1;i<=n;i++){
        c[i][0]=999999;
    }
    c[1][0]=0;
    q.push({0,1});
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        if(ch[t.second]==1){
            continue;
        }
        ch[t.second]=1;
        t.first=t.first*-1;
        for(auto f:a[t.second]){
            if(ch[f]==0){
                c[f][0]=min(c[f][0],t.first+1);
                if(c[f][0]==t.first+1){
                    c[f][1]=t.second;
                }
                q.push({c[f][0]*-1,f});
            }
        }
    }

    scanf("%d ",&m);
    for(j=0;j<m;j++){
        int s1=0,s[100010]={0};
        scanf("%d",&r);
        if(c[r][0]==999999){
            printf("-1\n");
        }
        else{
            s[s1]=r;
            int g=c[r][1];
            while(g!=1){
                s1++;
                s[s1]=g;
                g=c[g][1];
            }
            s1++;
            s[s1]=1;
            for(i=s1;i>=0;i--){
                printf("%d ",s[i]);
            }
            printf("\n");
        }
    }

}
