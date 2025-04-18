#include <iostream>
#include "vector"
#include "set"
#include <algorithm>
using namespace std;
const int N =1e5 + 10;
long long f(int k, const vector<int>& a, int l, int r) {
    long long ans = 0;
    for (int i = l; i <= r; ++i) {
        while (k % a[i] == 0) {
            k /= a[i];
        }
        ans += k;
    }
    return ans;
}


void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        set<int> pos[N];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]].insert(i);
        }

        while (q--) {
            int k, l, r;
            cin >> k >> l >> r;
            vector<int> factors;
            for(int i=1;i<=k/i;i++){
                if(k%i==0){
                    auto it = pos[i].lower_bound(l);
                    if(it !=pos[i].end()) factors.push_back(*it);
                    if(i != k/i){
                        it = pos[k/i].lower_bound(l);
                        if(it !=pos[k/i].end()) factors.push_back(*it);
                    }
                }
            }
            long long ans=0;
            sort(factors.begin(), factors.end());
            for(auto item:factors){
                if(item>r) break;
                if(k%a[item] == 0){
                    ans+=1ll*(item - l) *k;
                    l=item;
                    while(k%a[item] == 0)k /= a[item];
                }
            }
            ans+=1ll*(r-l+1)*k;
            cout << ans << endl;
        }

        for(int i=1;i<=n;i++){
            pos[a[i]].clear();
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/H.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}