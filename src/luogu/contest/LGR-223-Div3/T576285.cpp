#include <iostream>

using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        int x;
        cin >>x;
        sum += x;
    }
    cout << max(sum-(n-1ll)*k,0ll) << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-223-Div3/in/T576285.in", "r", stdin);
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