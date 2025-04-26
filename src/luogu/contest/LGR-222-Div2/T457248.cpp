#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
void solve() {
    string s;
    cin >> n >> k >> s;
    vector<pair<char, int>> b;
    char c = s[0];
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == c) {
            cnt++;
        } else {
            b.emplace_back(c, cnt);
            c = s[i];
            cnt = 1;
        }
    }
    b.emplace_back(c, cnt);

    int cnt_1 = 0;
    for (auto& [ch, len] : b) {
        if (ch == '1') ++cnt_1;
    }

    if (cnt_1 <= 1) {
        cout << max(0, cnt_1) << '\n';
        return;
    }

    vector<int> p;
    for (size_t i = 1; i + 1 < b.size(); ++i) {
        if (b[i].first == '0' &&
            b[i - 1].first == '1' &&
            b[i + 1].first == '1') {
            p.push_back(b[i].second);
        }
    }

    sort(p.begin(), p.end());

    int now = 0;
    for (int item : p) {
        if (now + item <= k) {
            now += item;
            cnt_1--;
        } else {
            break;
        }
    }

    cout << cnt_1 << '\n';
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-222-Div2/in/T457248.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}