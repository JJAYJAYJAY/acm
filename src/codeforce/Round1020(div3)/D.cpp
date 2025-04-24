#include <iostream>
#include <vector>
using namespace std;


void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    vector<int> prefix(m + 1, -1);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j < m && a[i] >= b[j]) {
            j++;
            prefix[j] = i;
        }
    }
    if(j<m){
        vector<int> suffix(m, n);
        j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && a[i] >= b[j]) {
                suffix[j] = i;
                j--;
            }
        }
        int min_k = INT_MAX;
        for (int s = 1; s <= m; ++s) {
            int pre_idx = s - 1;
            if (pre_idx > 0 && prefix[pre_idx] == -1) {
                continue;
            }
            int pre_pos = (pre_idx >= 0) ? prefix[pre_idx] : -1;

            int suf_pos;
            if (s >= m) {
                suf_pos = n;
            } else {
                if (suffix[s] == n) continue;
                suf_pos = suffix[s];
            }

            if (pre_pos < suf_pos) {
                min_k=min(min_k,b[s - 1]);
            }
        }

        if (min_k != INT_MAX) {
            cout << min_k << endl;
        } else {
            cout << "-1"<<endl;
        }
    }else{
        cout<<0<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1020(div3)/in/D.in", "r", stdin);
#endif
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}