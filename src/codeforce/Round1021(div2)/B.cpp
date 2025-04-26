#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using ll = long long;
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a;
    for(int i =0 ;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int L = ( (n - k) + 1 ) / 2;
    ll low  = a[L - 1];
    ll high = a[n - L];

    ll ans = 0;
    if (high >= low) {
        ans = high - low + 1;
    }
    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1021(div2)/in/B.in", "r", stdin);
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