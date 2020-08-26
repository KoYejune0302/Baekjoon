#include<stdio.h>
#include<utility>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;

pair<double,double> s,f,a[110];
double b[110][110],k[110];
priority_queue<pair<double, int> > q;
int n;

double time(int p,int q){
    double h=sqrt(pow(a[p].first-a[q].first,2)+pow(a[p].second-a[q].second,2));
    return min(fabs(h-50)/5+2,h/5);
}

int main(){
    int i,j,v[110]={0};
    scanf("%lf %lf",&s.first,&s.second);
    scanf("%lf %lf",&f.first,&f.second);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf %lf",&a[i].first,&a[i].second);
    }
    a[n+1]=f;
    for(i=1;i<=n+1;i++){
        for(j=1;j<=n+1;j++){
            if(i!=j){
                b[i][j]=time(i,j);
            }
        }
    }
    for(i=1;i<=n+1;i++){
        b[0][i]=sqrt(pow(s.first-a[i].first,2)+pow(s.second-a[i].second,2))/5;
    }
    for(i=0;i<=n+1;i++){
        k[i]=100000000000000.0;
    }
    q.push({0.0,0});
    k[0]=0.0;
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        if(v[t.second]==1){
            continue;
        }
        v[t.second]=1;
        for(i=1;i<=n+1;i++){
            if(v[i]==0){
                k[i]=min(k[i],k[t.second]+b[t.second][i]);
                q.push({k[i]*-1,i});
            }
        }
    }
    printf("%f",k[n+1]);
}
