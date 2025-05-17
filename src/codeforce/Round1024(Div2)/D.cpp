#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

long long ans=0;
void merge_sort(vector<int> &q, int l, int r)
{
    static vector<int> tmp(1000000);
    if (l >= r)  return;
    int mid = (l + r )/2;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int k = l, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else
        {
            tmp[k++] = q[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l; i <= r; i++) q[i] = tmp[i];
}


void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b, c;
    ans=0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 0) b.push_back(a[i]);
        else c.push_back(a[i]);
    }

    //统计逆序对
    merge_sort(b, 0, b.size()-1);
    merge_sort(c, 0, c.size()-1);

    vector<int> res(n);
    int e = 0, o = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            res[i] = b[e++];
        } else {
            res[i] = c[o++];
        }
    }

    if(ans%2==1){
        swap(res[n-3], res[n-1]);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1024(Div2)/in/D.in", "r", stdin);
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