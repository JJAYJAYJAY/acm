#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

using ll=long long;
const int MAX = 6500000;
vector<bool> st(MAX + 1, false);
vector<int> ps;

void solve(vector<ll> &P,int Pn) {
    int n;
    cin>>n;
    vector<ll> a(n,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    vector<ll> A(n+1, 0);
    for(int i = 1; i <= n; i++)
        A[i] = A[i-1] + a[i-1];

    int l = 0, r = min(n, Pn), ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(A[mid] >= P[mid]){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << (n - ans) << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound178(div2)/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;
    ps.reserve(220000);
    for(int i = 2; i <= MAX; i++){
        if(!st[i]){
            ps.push_back(i);
            if ((ll)i * i <= MAX) {
                for(int j = i*i; j <= MAX; j += i)
                    st[j] = true;
            }
        }
    }
    int Pn = ps.size();
    vector<ll> P(Pn+1, 0);
    for(int i = 1; i <= Pn; i++){
        P[i] = P[i-1] + ps[i - 1];
    }
    while (work--) {
        solve(P,Pn);
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}
