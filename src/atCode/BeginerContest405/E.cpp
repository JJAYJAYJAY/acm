#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
const int MAX = 5e6;
using ll = long long;
vector<ll> fac(MAX+1), ifac(MAX+1);

ll modpow(ll a, ll e=MOD-2){
    ll r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD; e>>=1;
    }
    return r;
}

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    fac[0]=1;
    for(int i=1;i<=MAX;i++) fac[i]=fac[i-1]*i%MOD;
    ifac[MAX]=modpow(fac[MAX]);
    for(int i=MAX;i>0;i--) ifac[i-1]=ifac[i]*i%MOD;
    if(A==0){
        int n = B+C+D;
        cout<<fac[n] * ifac[D] % MOD * ifac[n-D] % MOD<<endl;
    }else{
        ll ans = 0;
        for (int i = 0; i <= B; i++) {
            int n= A-1 + i,k =i;
            ll t1 = fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
            n= B-i+C+D,k=C;
            ll t2 = fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
            ans = (ans + t1 * t2) % MOD;
        }
        cout << ans << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginerContest405/in/E.in", "r", stdin);
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