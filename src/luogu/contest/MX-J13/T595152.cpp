#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        unsigned int n, k;
        cin >> n >> k;
        unsigned long long res = (n + 1ULL) * (1ULL << k);
        for (unsigned int i = k + 1; (1ULL << i) - (1ULL << k) <= n; ++i) {
            unsigned long long mask = (1ULL << i) - (1ULL << k);
            unsigned long long full = (n - mask) / (1ULL << i);
            unsigned long long rem = (n - mask) % (1ULL << i) + 1;
            unsigned long long cnt = full * (1ULL << k) + min(1ULL << k, rem);
            res += cnt * (1ULL << i);
        }
        cout << res << '\n';
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/MX-J13/in/T595152.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}