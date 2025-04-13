#include <iostream>

using namespace std;
int t;

void solve() {
    cin>>t;
    while(t--){
        long long a,b,x,y;
        cin>>a>>b>>x>>y;
        long long ans1,ans2,ans3;
        ans1 = min(a,b)*y;
        ans2 = a/2*x+ a%2*y;
        ans3 = b/2*x+ b%2*y;
        cout<<min(ans1,min(ans2,ans3))<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/MX-J13/in/T595151.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}