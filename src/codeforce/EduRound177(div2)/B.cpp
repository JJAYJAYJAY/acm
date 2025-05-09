#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
void solve() {
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> a(n+1);
    vector<ll> s(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=n;i>=1;i--){
        s[i] = s[i+1]+a[i];
    }
    ll l=1,r=n*k;
    ll ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        ll len = n*k-mid+1;
        ll sum = (len/n)*s[1]+(len%n?s[n-(len%n-1)]:0);
        if(sum>=x){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound177(div2)/in/B.in", "r", stdin);
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