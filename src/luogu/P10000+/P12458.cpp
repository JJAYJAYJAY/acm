#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
int x, y, z, p, a[N], b[N], c[N];

void solve() {
    cin >> x >> y >> z >> p;
    for(int i = 1; i <= x; ++i) cin >> a[i];
    for(int i = 1; i <= y; ++i) cin >> b[i];
    for(int i = 1; i <= z; ++i) cin >> c[i];
    sort(b + 1, b + y + 1);
    sort(c + 1, c + z + 1);
    int mn = c[1];
    int mx = c[z];
    int ans = -1;
    for(int i = 1; i <= x; ++i) {
        double bp = p - (mn + mx) / 2. - a[i]; int c;
        int P = lower_bound(b + 1, b + y + 1, bp) - b;
        if(P == 1) c = b[1]; else if(P == y + 1) c = b[y];
        else c = (b[P] - bp < bp - b[P - 1] ? b[P] : b[P - 1]);
        int s1 = abs(a[i] + c + mn - p);
        int s2 = abs(a[i] + c + mx - p);
        ans = max(ans, max(s1, s2));
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P12458.in", "r", stdin);
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