#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans1 = 1+ceil(log2(n-a+1))+ceil(log2(m));
    int ans2 = 1+ceil(log2(a))+ceil(log2(m));
    int ans3 = 1+ceil(log2(n))+ceil(log2(m-b+1));
    int ans4 = 1+ceil(log2(n))+ceil(log2(b));
    long long choice1 = ceil(log2(n))-ceil(log2(n-a+1));
    long long choice2 = ceil(log2(n))-ceil(log2(a));
    long long choice3 = ceil(log2(m))-ceil(log2(m-b+1));
    long long choice4 = ceil(log2(m))-ceil(log2(b));
    long long maxChoice = max(max(choice1, choice2), max(choice3, choice4));

    if (maxChoice == choice1) cout << ans1 << endl;
    else if (maxChoice == choice2) cout << ans2 << endl;
    else if (maxChoice == choice3) cout << ans3 << endl;
    else cout << ans4 << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1025(Div2)/in/B.in", "r", stdin);
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