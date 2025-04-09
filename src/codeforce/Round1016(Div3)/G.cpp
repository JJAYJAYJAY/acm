#include <iostream>

using namespace std;
const int N =100001000;
int son[N][2],idx,a[N],all[N];

void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int u = x>>i &1;
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    a[idx] = x;
}
int t;
int n,k;

void solve() {
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/G.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}