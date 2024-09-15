//
// Created by lyh on 2024/9/14.
//
//spfa+MCMF
#include "iostream"
#include <queue>
#include <cstring>

#define INF 0x7f7f7f7f
using namespace std;
struct Edge{
    int from,to,flow,cost,next;
}e[100000];
int ecnt=0;
int head[10000];

void add_edge(int from,int to,int flow,int cost){
    e[ecnt].from=from;
    e[ecnt].to=to;
    e[ecnt].flow=flow;
    e[ecnt].cost=cost;
    e[ecnt].next=head[from];
    head[from]=ecnt++;
}

void add(int from,int to,int flow,int cost){
    add_edge(from,to,flow,-cost);
    add_edge(to,from,0,cost);
}

int dis[10000],pre[10000],flow[10000];

bool sfpa(int s,int t){
    queue<int> q;
    bool inq[10000]={false};
    memset(dis,0x7f,sizeof(dis));
    dis[s]=0;
    q.push(s);
    inq[s]=true;
    flow[s]=INF;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if(e[i].flow>0&&dis[v]>dis[u]+e[i].cost){
                dis[v]=dis[u]+e[i].cost;
                pre[v]=i;
                flow[v]=min(flow[u],e[i].flow);
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    return dis[t]!=INF;
}
int ans=0;
int MCMF(int s,int t){
    while(sfpa(s,t)){
        int u=t;
        ans+=dis[t]*flow[t];
        while(u!=s){
            e[pre[u]].flow-=flow[t];
            e[pre[u]^1].flow+=flow[t];
            u=e[pre[u]].from;
        }
    }
    return ans;
}
int n;
int hashin(int x,int y) {
    return n*x+y+1;
}
int hashout(int x,int y) {
    return n*n + n * x + y + 1;
}
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    int g[10][10];
    memset(g,0,sizeof(g));
    int x,y,v;
    while (scanf("%d%d%d",&x,&y,&v) == 3) {
        if (x == 0 && y == 0 && v == 0) break;
        x--;
        y--;
        g[x][y] = v;
    }
    int s;
    s=0;
    int t=2*n*n+1;
    add(s,hashin(0,0),2,0);
    add(2*n*n,t,2,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            add(hashin(i,j),hashout(i,j),1,g[i][j]);
            add(hashin(i,j),hashout(i,j),1,0);
            if(i+1<n){
                add(hashout(i,j),hashin(i+1,j),1,0);
            }
            if(j+1<n){
                add(hashout(i,j),hashin(i,j+1),1,0);
            }
        }
    }
    MCMF(s,t);
    printf("%d",-MCMF(s,t));
    return 0;
}