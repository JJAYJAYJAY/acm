#include <iostream>
#include<vector>
#include <unordered_set>
using namespace std;
int get_mex(const vector<int>& a) {
    unordered_set<int> elements(a.begin(), a.end());
    int mex = 0;
    while (elements.count(mex)) mex++;
    return mex;
}

bool is_right(const vector<int>& a, int k, int x) {
    int n = a.size();

    int count = 0;
    unordered_set<int> current;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) current.insert(a[i]);  //找到合理的子数组
        if (current.size() == x) {
            count++;
            current.clear();
        }
    }
    return count >= k;//如果找完了数量还是不够，就说明x不行要继续缩小
}

int calc(const vector<int>& a, int k) {
    int mex = get_mex(a);
    int l = 0, r = mex+1;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (is_right(a, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int maxx=0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxx=max(maxx,a[i]);
        }
        cout << calc(a, k) << '\n';
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/E.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}