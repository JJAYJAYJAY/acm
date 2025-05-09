
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> p(n+1,0);
    vector<int> d(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int ans=0;
    vector<int> st(n+1,0);
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        int need = p[t];
        int now = t;
        if(!st[t]){
            st[t]=1;
            ans++;
        }
        while(need!=now&&!st[need]){
            ans++;
            now = need;
            need = p[need];
            st[now]=1;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound177(div2)/in/C.in", "r", stdin);
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