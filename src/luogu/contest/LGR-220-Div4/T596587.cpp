#include <iostream>

using namespace std;

int f,m,n;

void solve() {
    scanf("%d%d%d",&f,&m,&n);
    int cnt = 0 ;
    for(int i = 6;i<=n-1;i+=7){
        cnt++;
    }
    cout<<cnt*(2*f+m)<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596587.in","r",stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}