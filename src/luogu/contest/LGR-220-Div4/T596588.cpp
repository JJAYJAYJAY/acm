#include <iostream>

using namespace std;

int l,e;
void solve() {
    scanf("%d%d",&l,&e);

    if (l < 3) {
        cout << "Impossible" << endl;
        return;
    }

    bool m = (l >= 8) || (l >= 6 && e == 1);

    if (m) {
        cout << 3 << endl;
    } else {
        cout << 6 << endl;
    }

}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596588.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}