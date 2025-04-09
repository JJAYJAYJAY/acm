#include <iostream>

using namespace std;
int gcd(int a,int b){
    return b? gcd(b,a%b):a;
}
void solve() {
    long long a,m,b,n;
    cin >> a >> m >> b >> n;
    long long x = (a*b)/gcd(a,b);
    long long cnt = x / b;
    long long per = x / a + (cnt-1);
    long long z = n/gcd(cnt,n);
    long long ans=z*per;
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P10000+/in/P12048.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}