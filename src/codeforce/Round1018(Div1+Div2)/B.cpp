#include <iostream>
#include<vector>
#include "algorithm"
using namespace std;

void solve() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> l(n), r(n);
        long long l_total = 0, r_total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            l_total += 1ll*l[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
            r_total += 1ll*r[i];
        }

        vector<int> m(n);
        long long m_total = 0;
        for(int i = 0; i < n; ++i) {
            m[i] = min(l[i], r[i]);
            m_total += 1ll*m[i];
        }
//        long long ans = max(l_total, r_total);
        long long ans = l_total + r_total - m_total*2;
        sort(m.begin(), m.end(), greater<int>());
        for(int i=0;i<k;i++){
            if(i==k-1){
                ans+=2;
                m_total-=1;
            }else{
                ans+=m[i]*2;
                m_total-=m[i];
            }
        }
        ans+=m_total;
        cout << ans << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1018(Div1+Div2)/in/B.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}