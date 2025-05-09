#include <iostream>

using namespace std;
using ll=long long;
void solve() {
    ll a,b;
    cin>>a>>b;
    ll ans = 0;
    for (ll i = 1; i <= a; i++) {
        ans += ( b*(2*i - 1) + a ) / (2*a);
    }
    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P10562.in", "r", stdin);
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