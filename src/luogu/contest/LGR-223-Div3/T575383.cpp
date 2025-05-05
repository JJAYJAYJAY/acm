#include <iostream>
#include "vector"
using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1,0);
    int maxx=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            int x;
            cin>>x;
            a[x]++;
            maxx=max(maxx,a[x]);
        }
    }
    if(maxx>m){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-223-Div3/in/T575383.in", "r", stdin);
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