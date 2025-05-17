#include <iostream>

using namespace std;

void solve() {
    long long n, m, p, q;
    cin >> n >> m >> p >> q;

    if (n % p == 0) {
        if(m==n/p*q){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    } else {
        cout << "YES"<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1024(Div2)/in/A.in", "r", stdin);
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