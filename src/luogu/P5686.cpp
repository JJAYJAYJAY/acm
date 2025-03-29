#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);

    // 输入序列 a
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 输入序列 b
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    long long ans = 0;

    // 枚举所有区间 [l, r]
    for (int l = 1; l <= n; ++l) {
        long long sum_a = 0, sum_b = 0;
        for (int r = l; r <= n; ++r) {
            sum_a += a[r];
            sum_b += b[r];
            ans = (ans + sum_a * sum_b) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}