#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int n;
vector<int> a;
int dp[5005][5005], cnt[5005][5005];

int mex(const vector<int>& seg) {
    unordered_set<int> s(seg.begin(), seg.end());
    for (int i = 0; ; ++i) {
        if (!s.count(i)) return i;
    }
}


void solve() {
    int n;
    cin >> n;
    a.resize(n);
    vector<bool> used(n, false);
    vector<int> unknown_pos;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != -1) used[a[i]] = true;
        else unknown_pos.push_back(i);
    }

    vector<int> missing;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) missing.push_back(i);
    }

    // 清空 DP 表
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = cnt[i][j] = 0;

    // 枚举所有子段 [l, r]
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            unordered_set<int> s;
            bool valid = true;

            for (int i = l; i <= r; ++i) {
                if (a[i] != -1) {
                    if (s.count(a[i])) {
                        valid = false;
                        break;
                    }
                    s.insert(a[i]);
                }
            }

            if (!valid) continue;

            vector<int> seg;
            for (int i = l; i <= r; ++i) {
                if (a[i] != -1) seg.push_back(a[i]);
            }
            int m = mex(seg);
            dp[l][r] = m;
        }
    }

  
    int res = 0;
    for (int l = 0; l < n; ++l)
        for (int r = l; r < n; ++r)
            res = (res + dp[l][r]) % MOD;

    cout << res << '\n';
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1015(Div1+Div2)/in/E.in", "r", stdin);
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