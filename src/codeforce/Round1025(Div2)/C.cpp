#include <iostream>

using namespace std;
using ll = long long;
int mul(ll x){
    cout<<"mul "<<x<<endl;
    int y;
    cin>>y;
    return y;
}

int add(ll x) {
    cout << "add " << x << endl;
    int y;
    cin >> y;
    return y;
}

int digit() {
    cout << "digit" << endl;
    int y;
    cin >> y;
    return y;
}

int div(ll x) {
    cout << "div " << x << endl;
    int y;
    cin >> y;
    return y;
}

int check(){
    cout<<"!"<<endl;
    int y;
    cin>>y;
    return y;
}
void solve() {
    int n;
    cin>>n;
    mul(999999999);
    digit();
    if(n!=81){
        add(n-81);
    }
    check();
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1025(Div2)/in/C.in", "r", stdin);
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