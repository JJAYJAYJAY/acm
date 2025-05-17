#include <iostream>
#include<vector>
#include <set>
using namespace std;
int cnt[101];

void solve() {
    int n,m;
    cin>>n>>m;
    set<int> b;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=m) cnt[a[i]]++;
    }
    for(int x = 1; x <= m; x++){
        if(cnt[x] == 0){
            cout << 0 <<endl;
            return;
        }
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        ans++;
        cnt[a[i]]--;
        if(cnt[a[i]] == 0){
            cout << ans<<endl;
            return;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginerContest405/in/B.in", "r", stdin);
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