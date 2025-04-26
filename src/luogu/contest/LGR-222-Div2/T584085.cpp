#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    string T, S;
    cin >> n >> T >> S;

    vector<int> d1(n + 2), d2(n + 2);
    for(int i = 1; i <= n; i++){
        d1[i] = (T[i - 1] != S[i - 1]);
        d2[i] = (T[i] != S[i - 1]);
    }

    vector<int> c00(n+2), c11(n+2), c01(n+2);
    for(int i = 1; i <= n; i++){
        bool nxt0 = i + 2 <= n && (d1[i + 2] == 1);
        bool nxt1 = i + 2 <= n && (d2[i + 2] == 1);
        c00[i] = (d1[i] == 1 && !nxt0);
        c11[i] = (d2[i] == 1 && !nxt1);
        c01[i] = (d1[i] == 1 && !nxt1);
    }

    vector<int> p00(n+2,0), p11(n+2,0);
    for(int i = 1; i <= n; i++){
        p00[i] = p00[i-1] + c00[i];
        p11[i] = p11[i-1] + c11[i];
    }

    int mn = 1e9;
    for(int d = 1; d <= n+1; d++){
        int res = 0;
        if(d-3 >= 1) res += p00[d-3];
        res += (p11[n] - p11[d-1]);
        if(d-2 >= 1 && d-2 <= n) res += c01[d-2];
        if(d-1 >= 1 && d-1 <= n) res += c01[d-1];
        mn = min(mn, res);
    }

    cout << (mn + 1) << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-222-Div2/in/T584085.in", "r", stdin);
#endif
    int work;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}