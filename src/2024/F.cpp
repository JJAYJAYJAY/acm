#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    long long ans=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        ans+=x;
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/2024/in/F.in", "r", stdin);
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