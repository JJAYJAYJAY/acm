#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int score;
    cin >> score;

    vector<int> a(32);
    for (int i = 0; i < 32; ++i) {
        cin >> a[i];
    }

    int first = a[0];
    int second = a[2] - 1;
    const int third = 40;

    if (score >= first) {
        cout << "sidekick" << endl;
    } else if (score >= second) {
        cout << "sgnd" << endl;
    } else if (score >= third) {
        cout << "cxq" << endl;
    } else {
        cout << "kiku" << endl;
    }

}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P12004.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}