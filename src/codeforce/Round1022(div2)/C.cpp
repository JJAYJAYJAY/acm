#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> p(n+1,{-1,0});
    int j = 1;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        if(p[j-1].first == x){
            continue;
        }
        p[j] = {x, j};
        j++;
    }

    n = j;
    sort(p.begin()+1, p.end(), [&](auto &x, auto &y){
        return x.first > y.first;
    });
    vector<int> st(n+1, 0);
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int idx = p[i].second;
        if(st[idx-1]==0&&st[idx+1]==0){
            ans++;
        }
        st[idx] = 1;
    }

    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1022(div2)/in/C.in","r",stdin);
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