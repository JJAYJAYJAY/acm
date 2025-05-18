#include <iostream>
#include "cmath"
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    long long POW10[19] = {1};
    for (int i = 1; i <= 18; ++i) POW10[i] = POW10[i - 1] * 10;

    long long ans = 1;

    for (int i = 0; i < N; ++i) {
        long long x;
        cin >> x;
        __int128 prod = (__int128) ans * x;

        if (prod >= (__int128)POW10[K]) {
            ans = 1;
        } else {
            ans = (long long) prod;
        }
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginnerContest406/in/B.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}