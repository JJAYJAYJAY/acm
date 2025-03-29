//
// Created by lyh on 2025/3/23.
//
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e8+10;

struct node{
    int x,y;
}nodes[5010];

int h[10020],e[N],ne[N],idx,w[N];

int dist[10020];
int st[10020];
int n,m;

void add(int a,int b,int c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

int dijkstra(){
    memset(dist,0x3f3f3f3f, sizeof dist);
    priority_queue<pair<long long,int>> heap;
    dist[1]=0;
    heap.push(make_pair(0,1));
    while(heap.size()){
        int t = heap.top().second;
        heap.pop();
        if(st[t]) continue;
        st[t]=1;
        for(int i = h[t];i != -1;i=ne[i]){
            int j = e[i] , k =w[i];
            if(dist[j]>dist[t]+k){
                dist[j] = dist[t]+k;
                heap.push(make_pair(-dist[j],j));
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&nodes[i].x,&nodes[i].y);
    }
    for(int i=1;i<=m;i++){
        int x,y,r,t;
        scanf("%d%d%d%d",&x,&y,&r,&t);
        for(int j = 1;j<=n;j++){
            node tmp = nodes[j];
            if(x-r<=tmp.x && x+r>=tmp.x && y-r<=tmp.y && y+r>=tmp.y){
                add(j,n+i,t);
                add(n+i,j,t);
            }
        }
    }
    int ans = dijkstra();
    if(ans == -1) cout<<"Nan";
    else cout<<ans/2;
}