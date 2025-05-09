#include <iostream>
#include <vector>
using namespace std;
using ll=unsigned long long;
vector<ll> num(31,0);

void solve() {
    ll l,r,k;
    cin>>l>>r>>k;

}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound177(div2)/in/E.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    num[1]=1ll;
    for(int i=2;i<=30;i++) num[i]=num[i-1]*4+1;
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}