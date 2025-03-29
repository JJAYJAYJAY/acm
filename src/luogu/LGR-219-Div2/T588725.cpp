#include <iostream>
#include <vector>
using namespace std;

int max_power(int n, int m, int k, const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    int max_result = 0;

    for (int ai : a) {
        for (int bj : b) {
            long long product = 1LL * ai * bj;  // 预计算乘积，防止整数溢出
            for (int ct : c) {
                max_result = max(max_result, static_cast<int>(product % ct));
            }
        }
    }

    return max_result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m), c(k);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) cin >> c[i];

    cout << max_power(n, m, k, a, b, c) << endl;

    return 0;
}
