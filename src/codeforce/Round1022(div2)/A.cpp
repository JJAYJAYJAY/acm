#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    cout<<n*n/4+1<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1022(div2)/in/A.in","r",stdin);
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