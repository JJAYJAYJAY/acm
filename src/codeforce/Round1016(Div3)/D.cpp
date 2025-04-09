#include <iostream>
#include <utility>
using namespace std;
int t;
int n,q;

typedef long long ll;
typedef pair<ll, ll> pii;

ll get_number(ll n, ll x, ll y) {
    if (n == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 2 && y == 2) return 2;
        if (x == 2 && y == 1) return 3;
        if (x == 1 && y == 2) return 4;
    }
    ll m = 1LL << (n - 1);
    ll area = m * m;
    if (x <= m && y <= m) {
        return get_number(n - 1, x, y);
    } else if (x > m && y > m) {
        return area + get_number(n - 1, x - m, y - m);
    } else if (x > m && y <= m) {
        return 2 * area + get_number(n - 1, x - m, y);
    } else {
        return 3 * area + get_number(n - 1, x, y - m);
    }
}

pii get_idx(ll n, ll d) {
    if (n == 1) {
        if (d == 1) return {1, 1};
        if (d == 2) return {2, 2};
        if (d == 3) return {2, 1};
        if (d == 4) return {1, 2};
    }
    ll m = 1LL << (n - 1); // m = 2^{n-1}
    ll area = m * m;
    if (d <= area) {
        pii coord = get_idx(n - 1, d);
        return {coord.first, coord.second};
    } else if (d <= 2 * area) {
        pii coord = get_idx(n - 1, d - area);
        return {coord.first + m, coord.second + m};
    } else if (d <= 3 * area) {
        pii coord = get_idx(n - 1, d - 2 * area);
        return {coord.first + m, coord.second};
    } else {
        pii coord = get_idx(n - 1, d - 3 * area);
        return {coord.first, coord.second + m};
    }
}


void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        while (q--) {
            string type;
            cin >> type;
            if (type == "->") {
                ll x, y;
                cin >> x >> y;
                cout << get_number(n, x, y) << '\n';
            } else if (type == "<-") {
                ll d;
                cin >> d;
                pii coord = get_idx(n, d);
                cout << coord.first << ' ' << coord.second << '\n';
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/D.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}