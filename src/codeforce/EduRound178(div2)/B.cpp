#include <iostream>
#include "vector"
#include <algorithm>
using ll=long long;
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n+2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<ll> s(n + 2);
    s[1] = a[1];
    for(int i = 2; i <= n; i++){
        s[i] = max(s[i - 1], a[i]);
    }

    vector<ll> b(n + 3, 0);
    for(int i = n; i >= 1; i--){
        b[i] = b[i + 1] + a[i];
    }


    for(int k = 1; k <= n; k++){
        ll mx = s[n - k + 1];
        ll suf = b[n - k + 2];
        cout << (mx + suf) << (k == n ? '\n' : ' ');
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound178(div2)/in/B.in", "r", stdin);
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