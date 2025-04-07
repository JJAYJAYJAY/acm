#include <iostream>

using namespace std;
int t;
int n,m;
int dp[1005][1005];

void solve() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&dp[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout<<dp[n][m]<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/acwing/in/1015.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}