#include <iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> t[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int x, y;
    cin >> x >> y;
    int ans = s[x - 1];
    for (int i = x - 1; i < y - 1; ++i) {
        ans += t[i];
    }
    for (int i = x; i < y - 1; ++i) {
        ans += s[i];
    }
    ans += s[y - 1];
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596590.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}