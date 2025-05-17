#include <iostream>
#include "cstring"
using namespace std;
const int N=3e5+8;
const int M = 2 * N;
int e[M], ne[M], h[N], idx;
int MAX_DEP=-1e9;
int cnt[N];
int depth[N];
int mx[N];

int st[N];
void dfs(int a,int b){
    st[a]=1;
    depth[a] = depth[b]+1;
    MAX_DEP = max(MAX_DEP,depth[a]-1);
    int count=0;
    for(int i=h[a];i!=-1;i=ne[i]){
        count++;
        int j = e[i];
        if(st[j]) continue;
        dfs(j,a);
        mx[a] = max(mx[a],mx[j]+1);
    }
    if(count==1) mx[a]=1;
    cnt[mx[a]]++;
}

void add(int a,int b) {
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void solve() {
    int n,q;
    cin>>n>>q;
    memset(h,-1,sizeof h);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    cnt[mx[1]]--;
    for(int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
    }

    while(q--){
        int x;
        cin>>x;
        cout<<4*(n-1)-MAX_DEP-2*(cnt[x])<<" ";
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P12449.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}