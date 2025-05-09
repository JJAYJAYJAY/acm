#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
const int MAX = 5e5;
using ll = long long;
vector<ll> fac(MAX+1), ifac(MAX+1);

// 快速幂
ll modpow(ll a, ll e=MOD-2){
    ll r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD; e>>=1;
    }
    return r;
}


void solve() {
    vector<int> c(26);
    int sum=0;
    for(int i=0;i<26;i++){
        cin>>c[i];
        sum+=c[i];
    }
    for(int i=0;i<26;i++){
        if(c[i]>(sum+1)/2){
            cout<<"0"<<endl;
            return;
        }
    }

    vector<int> dp((sum+1)/2+1,0);
    dp[0]=1;
    for(int i=25;i>=0;i--){
        if(c[i]==0) continue;
        for(int j=(sum+1)/2;j>=c[i];j--){
            dp[j] = dp[j] + dp[j-c[i]];
        }
    }
    ll I =1;
    for(int i=0;i<=25;i++){
        I = I*ifac[c[i]]%MOD;
    }
    ll ans = fac[(sum+1)/2] * fac[(sum/2)]%MOD;
    ans  = ans * dp[((sum+1)/2)]%MOD;
    ans = ans * I%MOD;
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound177(div2)/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[0]=1;
    for(int i=1;i<=MAX;i++) fac[i]=fac[i-1]*i%MOD;
    ifac[MAX]=modpow(fac[MAX]);
    for(int i=MAX;i>0;i--) ifac[i-1]=ifac[i]*i%MOD;
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}