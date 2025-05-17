#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<char> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(3));
    if(a[1] == '0') {
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;
    }
    if(a[1] == 'R') {
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;
    }
    if(a[1] == 'B') {
        dp[1][0] = 0;
        dp[1][1] = 1;
        dp[1][2] = 0;
    }
    if(a[1] == 'G') {
        dp[1][0] = 0;
        dp[1][1] = 0;
        dp[1][2] = 1;
    }
    for(int i=2;i<=n;i++){
        if(a[i]=='0'){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2] ) % MOD;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        }
        if(a[i]=='R'){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        if(a[i]=='B'){
            dp[i][0] = 0;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
            dp[i][2] = 0;
        }
        if(a[i]=='G'){
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        }
    }
    long long ans = (dp[n][0] + dp[n][1] + dp[n][2])%MOD;
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/2024/in/M.in", "r", stdin);
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