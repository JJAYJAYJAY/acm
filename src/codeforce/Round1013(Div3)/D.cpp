#include <iostream>

using namespace std;
using ll=long long;
void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    ll l = 0, r = m;

    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if ((m / (mid + 1) * mid + m % (mid + 1)) * n >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1013(Div3)/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}