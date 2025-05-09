#include <iostream>

using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    if(k==1) {
        cout << "YES" << endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P10565.in", "r", stdin);
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