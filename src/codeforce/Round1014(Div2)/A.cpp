#include <iostream>

using namespace std;



void solve() {
    int n;
    cin>>n;
    int mx=INT_MIN;
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mx = max(mx,x);
        mn = min(mn,x);
    }
    cout<<mx-mn<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1014(Div2)/in/A.in", "r", stdin);
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