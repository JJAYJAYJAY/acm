#include <iostream>
#include "vector"

using namespace std;

struct BIT {
    int n;
    vector<int> f;
    BIT(int _n):n(_n),f(n+1,0){}
    void add(int i){
        for(;i<=n;i+=i&-i) {
            f[i]++;
        }
    }
    int sum(int i){
        int s=0;
        for(;i;i-=i&-i) {
            s+=f[i];
        }
        return s;
    }
    int qry(int l,int r){
        return sum(r)-sum(l-1);
    }
};

void solve() {
    int N,M,Q;
    cin>>N>>M;
    int P=2*N;
    vector<int> cov(P+2,0);
    vector<vector<int>> ms(P+2);
    for(int i=0,a,b;i<M;i++){
        cin>>a>>b;
        cov[a]++; cov[b]++;
        ms[b].push_back(a);
    }
    for(int i=1;i<=P;i++) cov[i]+=cov[i-1];
    cin>>Q;
    vector<int> ans(Q);
    vector<vector<pair<int,int>>> qs(P+2);
    for(int i = 0; i < Q; i++){
        int c, d;
        cin >> c >> d;
        qs[d].emplace_back(c, i);
    }

    BIT ft(P);
    for(int x = 1; x <= P; x++){
        for(int a : ms[x])
            ft.add(a);
        for(auto &pr : qs[x]){
            int c = pr.first, idx = pr.second;
            int E = cov[x-1] - cov[c];
            int I = ft.qry(c+1, x-1);
            ans[idx] = E - 2 * I;
        }
    }

    for(int v:ans) cout<<v<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginerContest405/in/F.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}