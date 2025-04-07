#include <iostream>
#include <algorithm>

using namespace std;
const int N =1e5+5;
int n,k;
int f[N];
int st[N];

int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];

}

struct edge{
    int a,b;
    long long w;
    bool operator < (const edge &o) const{
        return w>o.w;
    }
}edges[N];

long long all;
void solve() {

    for(int i=0;i<N;i++){
        f[i] = i;
        st[i] = 0;
    }

    scanf("%d%d", &n, &k);
    for(int i=1;i<=k;i++){
        int t;
        scanf("%d",&t);
        st[t] = 1;
    }

    for(int i=0;i<n-1;i++){
        scanf("%d%d%lld",&edges[i].a,&edges[i].b,&edges[i].w);
        all += edges[i].w;
    }
    sort(edges,edges+n-1);
    long long now =0;
    for(int i=0;i<n-1;i++){
        int fa = find(edges[i].a);
        int fb = find(edges[i].b);
        if(st[fa] && st[fb]) continue;
        f[fa] = fb;
        now+= edges[i].w;
        st[fa] = st[fb] = st[fa]|st[fb];
    }
    cout<<all-now<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P2000-P3000/in/P2700.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}