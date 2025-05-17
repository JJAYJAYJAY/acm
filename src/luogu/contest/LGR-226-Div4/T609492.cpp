#include <iostream>

using namespace std;

void solve() {
    int k;
    char c;
    cin>>k>>c;
    int ans=0;
    for(int i=k;i<=255;i++){
        ans+=(i-k+1)*(i-k+1);
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-226-Div4/in/T609492.in", "r", stdin);
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