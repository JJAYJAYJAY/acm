#include <iostream>
#include "vector"
#include <cmath>
using namespace std;
using ll=long long;
const int MAX = 100000;
vector<bool> st(MAX + 1, false);
vector<int> ps;

void solve() {
    for(int i = 2; i <= MAX; i++){
        if(!st[i]){
            ps.push_back(i);
            if ((ll)i * i <= MAX) {
                for(int j = i*i; j <= MAX; j += i)
                    st[j] = true;
            }
        }
    }

    int n;
    cin>>n;

    int len = 1;
    while (len * (len - 1) / 2 < n) len++;
    int total = len * (len - 1) / 2;
    int rest = total - n;
    vector<int> ans1;
    int j=1;
    while(rest>0){
        if(rest-j>=0){
            rest -= j;
            j++;
        }else{
            ans1.push_back(j);
            len-=j;
            j=1;
        }
    }
    if(j!=1){
        ans1.push_back(j);
        len -= j;
    }
//    cout<<len<<endl;
    for(int i=0;i<len;i++){
        ans1.push_back(1);
    }

    vector<ll> ans;
    int idx = 0;
    for (int sz : ans1) {
        ll p = ps[idx++];
        for (int i = 0; i < sz; ++i)
            ans.push_back(p);
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << ' ';
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/2024/in/I.in", "r", stdin);
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