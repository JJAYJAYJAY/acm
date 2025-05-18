#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;
const int MAX = 60;
using ll = long long;
vector<ll> pow2(MAX+1, 1);
ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

ll mul(ll a, ll b) {
    return (a % MOD) * (b % MOD) % MOD;
}

void solve() {
    long long n;
    int k;
    cin>>n>>k;

    vector<int> bits;
    for(int i=MAX;i>=0;i--){
        bits.push_back( int((n >> i) & 1ll) );
    }
    vector dp_count(62, vector<vector<ll>>(k+1, vector<ll>(2, 0)));
    vector dp_sum(62, vector<vector<ll>>(k+1, vector<ll>(2, 0)));

    dp_count[0][0][1] = 1;

    for(int i = 0; i <= 60; i++){
        ll weight = pow2[60 - i];

        for(int used1 = 0; used1 <= k; used1++){
            for(int tight = 0; tight <= 1; tight++){
                ll ways = dp_count[i][used1][tight];
                ll ssum = dp_sum  [i][used1][tight];
                if (!ways) continue;

                int maxd = tight ? bits[i] : 1;
                for(int d = 0; d <= maxd; d++){
                    int nt = (tight && d == maxd);
                    int nu = used1 + d;
                    if (nu > k) continue;

                    dp_count[i+1][nu][nt] = add(dp_count[i+1][nu][nt], ways);

                    ll addv = mul(ways, mul(d, weight));
                    dp_sum[i+1][nu][nt] = add(dp_sum[i+1][nu][nt],add(ssum, addv));
                }
            }
        }
    }

    ll ans = add(dp_sum[61][k][0], dp_sum[61][k][1]);
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginnerContest406/in/E.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;

    for(int i = 1;i <= MAX; i++){
        pow2[i] = add(pow2[i-1], pow2[i-1]);
    }
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}