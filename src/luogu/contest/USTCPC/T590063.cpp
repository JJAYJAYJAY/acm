#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, M;
vector<vector<long long>> tree;
vector<long long> a;
long long max_mod = -1e9;

void dfs(long long u, long long parent, long long current_sum) {
    current_sum = (current_sum + a[u]) % M;
    if (current_sum > max_mod) {
        max_mod = current_sum;
    }
    for (long long v : tree[u]) {
        if (v != parent) {
            dfs(v, u, current_sum);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/USTCPC/in/T590063.in", "r", stdin);
#endif
    cin >> n >> M;
    tree.resize(35);
    a.resize(35);
    for (long long i = 2; i <= n; ++i) {
        long long f;
        cin >> f;
        tree[f].push_back(i);
        tree[i].push_back(f);
    }
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= M;
    }

    for (long long u = 1; u <= n; ++u) {
        dfs(u, -1, 0);
    }

    cout << max_mod << endl;
#ifdef LOCAL
    fclose(stdin);
#endif
    return 0;
}