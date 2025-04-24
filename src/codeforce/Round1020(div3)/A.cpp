#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void solve() {
    int n;
    string s;
    cin>> n;
    cin >> s;
    int cnt_1 = 0;
    for (char c : s) {
        if (c == '1') cnt_1++;
    }

    int total_ones = n * cnt_1 + (n - 2 * cnt_1);
    cout << total_ones << endl;

}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1020(div3)/in/A.in", "r", stdin);
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