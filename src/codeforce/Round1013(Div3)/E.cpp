#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e7;
using ll = long long;
vector<bool> st(MAX + 1, false);
vector<int> ps;

void solve() {
    int n;
    cin>>n;
    int ans= 0;
    for(auto p:ps){
        if(p > n) break;
        ans+=n/p;
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1013(Div3)/in/E.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i <= MAX; i++){
        if(!st[i]){
            ps.push_back(i);
            if ((ll)i * i <= MAX) {
                for(int j = i*i; j <= MAX; j += i)
                    st[j] = true;
            }
        }
    }

    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}