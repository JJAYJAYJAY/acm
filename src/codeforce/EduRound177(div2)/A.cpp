#include <iostream>

using namespace std;

void solve() {
    int n;
    cin>>n;
    cout<<n*3*4/3/2<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound177(div2)/in/A.in", "r", stdin);
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