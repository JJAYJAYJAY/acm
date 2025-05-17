#include <iostream>
#include "vector"
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if (n <= 2) {
        cout << n << endl;
        return;
    }
    vector<int> dp(n+1,2);
    vector<int> sub(n+1);
    for(int i=1;i<n;i++){
        sub[i] = a[i]-a[i-1];
    }
    dp[0]=1;
    int mx = -1;
    for(int i=1;i<n;i++){
        if(sub[i]==sub[i-1]){
            dp[i] = dp[i-1]+1;
        }
        mx = max(mx,dp[i]);
    }
    cout<<mx<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-226-Div4/in/T609489.in", "r", stdin);
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