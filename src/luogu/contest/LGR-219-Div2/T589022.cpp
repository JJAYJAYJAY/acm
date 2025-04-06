#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244853;

long long mod_inverse(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    vector<int> p_mod(n);
    for (int i = 0; i < n; ++i) {
        cin >> p_mod[i];
    }

    vector<long long> dp(m, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        vector<long long> new_dp(m, 0);
        int ai_mod = a[i];
        long long prob_right = p_mod[i];
        long long prob_wrong = (1 - prob_right + MOD) % MOD;
        for (int j = 0; j < m; ++j) {
            if (dp[j] == 0) continue;
            // Case 1: solve the i-th problem correctly
            int new_j = (j + ai_mod) % m;
            new_dp[new_j] = (new_dp[new_j] + dp[j] * prob_right) % MOD;
            // Case 2: solve the i-th problem wrongly
            new_dp[j] = (new_dp[j] + dp[j] * prob_wrong) % MOD;
        }
        dp = move(new_dp);
    }

    cout << dp[0] << '\n';

    return 0;
}