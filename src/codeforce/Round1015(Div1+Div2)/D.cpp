#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> ans(n+1,0);
    if(n - m*k < k){
        for(int i = 0; i < n; i++){
            cout << (i % k) << ' ';
        }
    }
    else {
        long long d = n / (m + 1);
        for(int i = 0; i < n; i++){
            cout << (i % d) << ' ';
        }
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1015(Div1+Div2)/in/D.in", "r", stdin);
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