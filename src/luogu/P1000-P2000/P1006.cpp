//
// Created by lyh on 2024/9/15.
//
#include "iostream"
#include "queue"
#include "cstring"
#define MAXN 100000
#define INF 0x7f7f7f7f
using namespace std;
struct Edge{
    int from,to,weight,flow,next;
}e[MAXN];
int head[MAXN];
int ecnt=0;
void add_edge(int from,int to,int flow,int weight){
    e[ecnt].from=from;
    e[ecnt].to=to;
    e[ecnt].weight=weight;
    e[ecnt].flow=flow;
    e[ecnt].next=head[from];
    head[from]=ecnt++;
}
void add(int from,int to,int flow,int weight){
    add_edge(from,to,flow,weight);
    add_edge(to,from,0,-weight);
}

int dis[MAXN],pre[MAXN],flow[MAXN];
bool sfpa(int s,int t){
    queue<int> q;
    bool inq[MAXN];
    memset(dis,0x7f,sizeof(dis));
    memset(inq,false,sizeof(inq));
    dis[s]=0;
    flow[s]=INF;
    q.push(s);
    inq[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].to;

            if(e[i].flow>0&&dis[v]>dis[u]+e[i].weight){
                dis[v]=dis[u]+e[i].weight;
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
        int f=flow[t];
        ans+=f*dis[t];
        for(int i=t;i!=s;i=e[pre[i]].from){
            e[pre[i]].flow-=f;
            e[pre[i]^1].flow+=f;
        }
    }
    return ans;
}

int n,m;
int hashin(int x,int y) {
    return m*x+y+1;
}
int hashout(int x,int y) {
    return n*m + m * x + y + 1;
}

int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    int g[n][m];
    memset(g,0,sizeof(g));
    int v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&v);
            g[i][j]=v;
        }
    }
    int s=0;
    int t=n*m+m*n+1;
    add(s,1,2,0);
    add(2*n*m,t,2,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (i == 0 && j == 0) {
                add(hashin(i,j),hashout(i,j),2,-g[i][j]);
            }
            if (i == n-1 && j == m-1) {
                add(hashin(i,j), hashout(i,j),2,-g[i][j]);
            } else{
                add(hashin(i,j),hashout(i,j),1,-g[i][j]);
            }
            if(i+1<n){
                add(hashout(i,j),hashin(i+1,j),1,0);
            }
            if(j+1<m){
                add(hashout(i,j),hashin(i,j+1),1,0);
            }
        }
    }
    printf("%d",-MCMF(s,t));
    return 0;
}