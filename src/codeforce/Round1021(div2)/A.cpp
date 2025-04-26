#include <iostream>
#include<vector>
using namespace std;

void solve() {
    string s;
    cin>>s;
    vector<int> cnt(10, 0); // 统计每个数字出现次数
    for (char c : s) {
        cnt[c - '0']++;
    }

    string result = "";
    for (int i = 0; i < 10; ++i) {
        int need = 10 - i;
        for (int d = need; d <= 9; ++d) {
            if (cnt[d]) {
                result += (char)(d + '0');
                cnt[d]--;
                break;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (cnt[i]) {
            result += (char)(i + '0');
            break;
        }
    }

    cout << result << '\n';

}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1021(div2)/in/A.in", "r", stdin);
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