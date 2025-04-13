#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct P {
    int x, y;
    bool operator==(const P &o) const {
        return x == o.x && y == o.y;
    }
};

namespace std {
    template <>
    struct hash<P> {
        size_t operator()(const P &p) const {
            return (size_t)p.x << 32 | p.y;
        }
    };
}

const int N = 1e6 + 10;
vector<int> g[N];
int pu[N], pv[N], d[N];
int n;

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; ++u) {
        if (pu[u] == -1) {
            d[u] = 0;
            q.push(u);
        } else {
            d[u] = -1;
        }
    }
    bool f = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (pv[v] == -1) {
                f = true;
            } else if (d[pv[v]] == -1) {
                d[pv[v]] = d[u] + 1;
                q.push(pv[v]);
            }
        }
    }
    return f;
}

bool dfs(int u) {
    for (int v : g[u]) {
        if (pv[v] == -1 || (d[pv[v]] == d[u] + 1 && dfs(pv[v]))) {
            pu[u] = v;
            pv[v] = u;
            return true;
        }
    }
    d[u] = -1;
    return false;
}

int hk() {
    fill(pu, pu + n + 1, -1);
    fill(pv, pv + n + 1, -1);
    int r = 0;
    while (bfs()) {
        for (int u = 1; u <= n; ++u) {
            if (pu[u] == -1 && dfs(u)) {
                ++r;
            }
        }
    }
    return r;
}
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<P> ps(n + 1);
    unordered_map<P, int> mp;
    mp.reserve(n);
    for (int i = 1; i <= n; ++i) {
        cin >> ps[i].x >> ps[i].y;
        mp[ps[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        P p = ps[i];
        int x = p.x + 1;
        int y = p.y;
        P nxt;

        nxt = {x, y + 1};
        auto it = mp.find(nxt);
        if (it != mp.end()) {
            g[i].push_back(it->second);
        }

        nxt = {x, y};
        it = mp.find(nxt);
        if (it != mp.end()) {
            g[i].push_back(it->second);
        }

        nxt = {x, y - 1};
        it = mp.find(nxt);
        if (it != mp.end()) {
            g[i].push_back(it->second);
        }
    }

    int mx = hk();
    int ans = n - mx;

    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/MX-J13/in/T595153.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}