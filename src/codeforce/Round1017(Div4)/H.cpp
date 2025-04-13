#include <iostream>
#include "vector"
using namespace std;
long long f(int k, const vector<int>& a, int l, int r) {
    long long ans = 0;
    for (int i = l; i <= r; ++i) {
        while (k % a[i] == 0) {
            k /= a[i];
        }
        ans += k;
    }
    return ans;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        while (q--) {
            int k, l, r;
            cin >> k >> l >> r;
            cout << f(k, a, l, r) << '\n';
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/H.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}