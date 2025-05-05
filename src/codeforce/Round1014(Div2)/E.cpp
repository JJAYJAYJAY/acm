#include <iostream>

using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll binpow (ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a; res %= mod;
        }
        a *= a; a %= mod; n >>= 1;
    }
    return res;
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    int cnt=0,b_cnt=0;
    for(ll i = 0; i < k; i++) {
        ll x,y,c; cin >> x>>y>>c;
        if ((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m)) continue;
        if (x == 1 || y == 1 || x == n || y == m) {
            ++cnt;
            b_cnt += c;
        }
    }
    if(cnt==(2*(n+m-4))){
        if(b_cnt%2==1){
            cout<<0<<endl;
        }else{
            cout<<binpow(2ll,n*m-k)<<endl;
        }
    }else{
        cout<<binpow(2ll,n*m-k-1)<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1014(Div2)/in/E.in","r",stdin);
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