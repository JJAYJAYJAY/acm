#include <iostream>
#include <cstring>
#include "vector"
#include "algorithm"
#define int long long
using namespace std;

const int N =1010;
int dp_x[N][2], dp_y[N][2];

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> h(n+2, vector<int>(n+2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> h[i][j];
        }
    }
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            dp_x[i][j] = 1e18;
            dp_y[i][j] = 1e18;
        }
    }
    dp_x[1][0] = 0;
    dp_x[1][1] = a[1];
    for(int i=2;i<=n;i++){
        for(int k=0;k<2;k++){
            for(int last_k=0;last_k<2;last_k++){
                int flag = true;
                for(int j=1;j<=n;j++){
                    if(h[i-1][j]+last_k == h[i][j]+k){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    dp_x[i][k] = min(dp_x[i][k],dp_x[i-1][last_k]+a[i]*k);
                }
            }
        }
    }
    if(dp_x[n][0] == 1e18 && dp_x[n][1] == 1e18){
        cout << -1 << endl;
        return;
    }
    dp_y[1][0] = 0;
    dp_y[1][1] = b[1];
    for(int i=2;i<=n;i++){
        for(int k=0;k<2;k++){
            for(int last_k=0;last_k<2;last_k++){
                int flag = true;
                for(int j=1;j<=n;j++){
                    if(h[j][i-1]+last_k == h[j][i]+k){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    dp_y[i][k] = min(dp_y[i][k],dp_y[i-1][last_k]+b[i]*k);
                }
            }
        }
    }
    if(dp_y[n][0] == 1e18 && dp_y[n][1] == 1e18){
        cout << -1 << endl;
        return;
    }
    cout<<min(dp_x[n][0],dp_x[n][1])+min(dp_y[n][0],dp_y[n][1])<<endl;
}

signed main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1018(Div1+Div2)/in/C.in", "r", stdin);
#endif
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}