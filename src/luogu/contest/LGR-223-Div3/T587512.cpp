#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
    int n, w;
    cin>>n >> w;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> d(n);
    for(int j = 0; j < n; j++){
        d[j] = a[j] - j;
    }
    sort(d.begin(), d.end(), greater<ll>());
    ll c = 0;
    if (w < n) {
        c = max(0LL, d[w]);
    }
    ll mx = 0;
    for(int j = 0; j < n; j++){
        ll t = c + j;
        mx += min(a[j], t);
    }


    ll ans = c * w + (sum - mx);
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-223-Div3/in/T587512.in", "r", stdin);
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