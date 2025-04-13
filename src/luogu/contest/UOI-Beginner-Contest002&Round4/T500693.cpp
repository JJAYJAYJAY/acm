#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N =1e6+5;


void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> a(n, 0);
    int carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        int total = b[i] * 2 - carry;
        if (total < 0) {
            total += 20;
            carry = 2;
        } else if (total >= 20) {
            total -= 20;
            carry = -2;
        } else {
            carry = 0;
        }
        a[i] = total / 2;
    }
    bool valid = true;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum = sum * 10 + a[j];
            sum %= (10 * n);
        }
        double val = (double)sum / (pow(10, n) - 1);
        double rounded = round(val * pow(10, i + 1)) / 10.0;
        int digit = (int)rounded % 10;
        if (digit != b[i]) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            a[i] += carry;
            carry = a[i] / 10;
            a[i] %= 10;
        }
    }

    for (int num : a) {
        cout << num;
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/UOI-Beginner-Contest002&Round4/in/T500693.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}