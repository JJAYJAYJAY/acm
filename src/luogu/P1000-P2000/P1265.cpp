//
// Created by lyh on 2025/3/21.
//
#include <iostream>
#include "cstring"
#include "cmath"
using namespace std;
const int N= 5010;

int n;
struct point{
    long long x,y;
}cities[N];
long long dist[N];
int st[N];
long long dis(point a,point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double prim(){
    double res=0;
    memset(dist,0x3f,sizeof dist);
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[j]<dist[t])){
                t=j;
            }
        }
        if(i){
            res+=sqrt(dist[t]);
        }
        st[t]= 1;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dis(cities[t],cities[j]));
        }
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&cities[i].x,&cities[i].y);
    }
    printf("%.2lf",prim());
}