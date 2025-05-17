#include <iostream>
#include <vector>

using namespace std;

bool check(char x,char y){
    return x==y||x=='?'||y=='?';
}

void solve() {
    string s;
    cin>>s;
    int n=s.length();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && check(s[l], s[r])) {
            ++ans;
            --l; ++r;
        }
    }
    for (int i = 0; i < n-1; i++) {
        int l = i, r = i + 1;
        while (l >= 0 && r < n && check(s[l], s[r])) {
            ++ans;
            --l; ++r;
        }
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-226-Div4/in/T609494.in", "r", stdin);
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