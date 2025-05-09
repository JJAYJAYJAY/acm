#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 998244353;
using ll = long long;
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> s(n+2);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    vector<vector<ll>> dp(n+2, vector<ll>(m+2, 0));
    vector<vector<ll>> sum(n+2, vector<ll>(m+2, 0));
    vector<vector<ll>> X(n+2);
    for(int i=0;i<m;i++){
        dp[n][i] = (s[n][i] == 'X') ? 1 : 0;
        sum[n][i] = dp[n][i];
        if(s[n][i] == 'X'){
            X[n].push_back(i);
        }
    }
    vector<vector<ll>> PPD(n+2, vector<ll>(m+2, 0));
    PPD[n][0] = dp[n][0];
    for(int i=1;i<=m;i++){
        PPD[n][i] = (PPD[n][i-1] + dp[n][i]) % MOD;
    }

    vector<vector<ll>> P(n+2, vector<ll>(m+2, 0));
    for(int i=0;i<X[n].size();i++){
        int l=max(0ll,X[n][i]-k);
        int r=min(m-1ll,X[n][i]+k);
        sum[n][X[n][i]] = (PPD[n][r] - (l-1<0?0:PPD[n][l-1]) + MOD) % MOD;
    }

    P[n][0] = sum[n][0];
    for(int i=1;i<=m;i++){
        P[n][i] = (P[n][i-1] + sum[n][i]) % MOD;
    }

    for(int i=n-1;i>=1;i--){
        for(int j=0;j<m;j++){
            if(s[i][j] == 'X'){
                //在X[i+1]中查找最近的
                int l = max(0,int(j-floor(sqrt((double)(k*k*1.0)-1))));
                int r = min(m-1,int(j+floor(sqrt((double)(k*k*1.0)-1))));
                dp[i][j] = (P[i+1][r] - (l-1<0?0:P[i+1][l-1]) + MOD) % MOD;
                sum[i][j] = dp[i][j];
                X[i].push_back(j);
            }
        }
        //dp前缀和
        PPD[i][0] = dp[i][0];
        for(int j=1;j<=m;j++){
            PPD[i][j] = (PPD[i][j-1] + dp[i][j]) % MOD;
        }
        for(int j=0;j<X[i].size();j++){
            int l = max(0ll,X[i][j]-k);
            int r = min(m-1ll,X[i][j]+k);
            sum[i][X[i][j]] = (PPD[i][r] - (l-1<0?0:PPD[i][l-1]) + MOD) % MOD;
        }
        //sum前缀和
        P[i][0] = sum[i][0];
        for(int j=1;j<=m;j++){
            P[i][j] = (P[i][j-1] + sum[i][j]) % MOD;
        }
    }
    cout << P[1][m-1] << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1013(Div3)/in/F.in", "r", stdin);
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