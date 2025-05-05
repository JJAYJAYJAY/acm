#include <iostream>
#include "vector"
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool flag = true;
    for(int i=1;i<=n;i++){
        if(a[i] != a[1]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "No" <<endl;
        return;
    }
    vector<int> b(n + 2), c(n + 2);
    b[1] = a[1];
    for (int i = 2; i <= n; i++)
        b[i] = gcd(b[i - 1], a[i]);
    c[n] = a[n];
    for (int i = n-1; i >= 1; i--)
        c[i] = gcd(c[i + 1], a[i]);

    int idx = -1;
    for (int i = 1; i <= n; i++) {
        int g;
        if (i == 1) g = c[2];
        else if (i == n) g = b[n - 1];
        else g = gcd(b[i - 1], c[i + 1]);
        if (a[i] != g) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "No" << endl;
    } else {
        cout << "Yes"<<endl;
        for (int i = 1; i <= n; i++) {
            cout << (i == idx ? 1 : 2) <<' ';
        }
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1023(div2)/in/A.in", "r", stdin);
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