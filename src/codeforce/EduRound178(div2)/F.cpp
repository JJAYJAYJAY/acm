#include <iostream>

using namespace std;

void solve() {
    int n;
    cin>>n;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound178(div2)/in/F.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;

    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}