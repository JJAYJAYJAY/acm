#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int64_t> x0(n), x1(n), y0(n), y1(n);

    for (int i = 0; i < n; ++i) {
        int64_t a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
        x0[i] = a;
        x1[i] = c;
        y0[i] = b;
        y1[i] = d;
    }

    int64_t min_x1 = *min_element(x1.begin(), x1.end());
    int64_t max_x0 = *max_element(x0.begin(), x0.end());
    int64_t min_y1 = *min_element(y1.begin(), y1.end());
    int64_t max_y0 = *max_element(y0.begin(), y0.end());

    int64_t dx = max(int64_t(0), max_x0 - min_x1);
    int64_t dy = max(int64_t(0), max_y0 - min_y1);

    cout << max(dx, dy) << '\n';
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-222-Div2/in/T584083.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}