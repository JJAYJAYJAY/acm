#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
using ll=long long;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    ll mn;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1, a.end());
    mn = a[1];
    if(a[2]==mn){
        cout<<"Yes"<<endl;
        return;
    }
    ll g = 0;
    for(int i=2;i<=n;i++){
        if(a[i]%mn==0){
            g = g==0 ? a[i] : gcd(g, a[i]);
        }
    }
    if(g == mn) cout<<"Yes"<<endl;
    else          cout<<"No"<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1015(Div1+Div2)/in/B.in", "r", stdin);
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