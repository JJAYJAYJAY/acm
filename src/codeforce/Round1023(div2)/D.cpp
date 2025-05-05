#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct T {
    int d, u, v;
    vector<int> p;
    bool operator<(const T& o) const {
        if (d != o.d) return d < o.d;
        if (u != o.u) return u < o.u;
        return v < o.v;
    }
};

vector<vector<int>> g;
vector<char> rm, vis, f;
vector<int> dis, fa;
vector<int> f_clr;

T get(int s, vector<int>& comp) {
    comp.clear();
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    comp.push_back(s);
    int a = s;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (dis[x] > dis[a] || (dis[x] == dis[a] && x > a)) a = x;
        for (int y : g[x]) {
            if (!rm[y] && !vis[y]) {
                vis[y] = 1;
                dis[y] = dis[x] + 1;
                q.push(y);
                comp.push_back(y);
            }
        }
    }
    for (int x : comp) vis[x] = 0;

    vector<int> comp2;
    q.push(a);
    vis[a] = 1;
    dis[a] = 0;
    fa[a] = -1;
    comp2.push_back(a);
    int b = a;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (dis[x] > dis[b] || (dis[x] == dis[b] && x > b)) b = x;
        for (int y : g[x]) {
            if (!rm[y] && !vis[y]) {
                vis[y] = 1;
                dis[y] = dis[x] + 1;
                fa[y] = x;
                q.push(y);
                comp2.push_back(y);
            }
        }
    }
    for (int x : comp2) vis[x] = 0;

    vector<int> path;
    for (int x = b; x != -1; x = fa[x]) path.push_back(x);
    return { (int)path.size(), max(a, b), min(a, b), path };
}

void init(int n){
    g.assign(n + 1, {});
    rm.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    f.assign(n + 1, 0);
    dis.assign(n + 1, 0);
    fa.assign(n + 1, -1);
}

void solve() {
    int n;
    cin >> n;
    init(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    priority_queue<T> pq;
    vector<int> comp;

    pq.push(get(1, comp));
    vector<int> ans;
    ans.reserve(3 * n);

    while (!pq.empty()) {
        T t = pq.top(); pq.pop();
        ans.push_back(t.d);
        ans.push_back(t.u);
        ans.push_back(t.v);
        for (int x : t.p) rm[x] = 1;

        f_clr.clear();
        for (int x : t.p) {
            for (int y : g[x]) {
                if (!rm[y] && !f[y]) {
                    T nt = get(y, comp);
                    pq.push(nt);
                    for (int z : comp) {
                        f[z] = 1;
                        f_clr.push_back(z);
                    }
                }
            }
        }
        for (int z : f_clr) f[z] = 0;
    }

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1023(div2)/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
#ifdef LOCAL
    fclose(stdin);
#endif
    return 0;
}
