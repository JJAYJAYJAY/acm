#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

const int MAX_N = 500;
const int MAX_M = 500;
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bitset<MAX_M> mask[MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val;
            cin >> val;
            if (val) {
                mask[i].set(j);
            }
        }
    }

    vector<int> base(n, 0);
    for (int x = 1; x < n; ++x) {
        base[x] = (mask[0] & mask[x]).count();
    }

    vector<int> max_common(n, 0);
    for (int x = 1; x < n; ++x) {
        int current_max = 0;
        for (int y = 0; y < n; ++y) {
            if (x == y) continue;
            current_max = max(current_max, (int)(mask[x] & mask[y]).count());
        }
        max_common[x] = current_max;
    }

    int max_total = 0;
    for (int x = 1; x < n; ++x) {
        if (base[x] >= max_common[x]) {
            max_total++;
        }
    }

    for (int j = 0; j < m; ++j) {
        if (mask[0].test(j)) continue;

        int current_invite = 0;
        for (int x = 1; x < n; ++x) {
            int new_common = base[x] + (mask[x].test(j) ? 1 : 0);
            if (new_common >= max_common[x]) {
                current_invite++;
            }
        }

        if (current_invite > max_total) {
            max_total = current_invite;
        }
    }

    cout << max_total << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P12245.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}