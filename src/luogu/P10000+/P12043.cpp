#include <iostream>

using namespace std;
const int N = 1e5 + 5;
struct Edge{
    int u,v,w;
}e[N];
int dist[510][510];
int n,m;

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

void solve() {
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = 0x3f3f3f3f;
        }
        dist[i][i] = 0;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        dist[e[i].u][e[i].v] = min(dist[e[i].u][e[i].v], e[i].w);
        dist[e[i].v][e[i].u] = min(dist[e[i].v][e[i].u], e[i].w);
    }
    floyd();
    for(int i=1;i<=m;i++){
        if(e[i].w> dist[e[i].u][e[i].v]){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for(int i=1;i<=m;i++){
        printf("%d ", e[i].w);
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P12043.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}