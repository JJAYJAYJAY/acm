#include <iostream>

using namespace std;
int t;

bool is_prime(int n){
    if(n == 2) return true;
    if(n == 1) return false;
    if (n < 2) return false;
    for (int i = 2; i <= n/i; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    scanf("%d", &t);
    while(t--){
        int x,k;
        cin>>x>>k;
        if(x==1){
            int y=1;
            k--;
            while(k--){
                y = y*10+1;
            }
            cout << (is_prime(y) ? "YES" : "NO") << endl;
            continue;
        }
        if(k>1) {
            cout << "NO" << endl;
            continue;
        }else{
            cout<<(is_prime(x) ? "YES" : "NO" )<< endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/C.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}