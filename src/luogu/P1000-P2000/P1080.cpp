#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int a[N],b[N];
int id[N];
int n;
void solve() {
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i]>>b[i];
        id[i]= i;
    }
    sort(id+1,id+n+1,[](int x,int y){
        return a[x]*b[x] < a[y]*b[y];
    });
    long long t=a[0];
    long long minn = -1e18;
    for(int i=1;i<=n;i++){
        minn = max(minn,t/b[id[i]]);
        t*=a[id[i]];
    }
    cout<<minn<<endl;
}

signed main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1080.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}