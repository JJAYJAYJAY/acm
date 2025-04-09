#include <iostream>
#define int __int128
using namespace std;
const int N = 100010, MOD = 998244353;
struct Segtree{
    int l, r;
    int sum, add;
} tr[N << 2];
int w[N];

void build(int u,int l,int r){
    if(l==r) tr[u] = {l, r, w[l], 0};
    else {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % MOD;
    }
}


void solve() {

}

signed main() {
#ifdef LOCAL
    freopen("src/luogu/P4000-P5000/in/P4927.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}