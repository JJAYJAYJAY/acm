#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;



int get_pri(char t) {
    if (t == 'O') return 3;
    if (t == 'C') return 2;
    return 1;
}

string next_day(const string& d) {
    int y = stoi(d.substr(0, 4));
    int m = stoi(d.substr(4, 2));
    int day = stoi(d.substr(6, 2));
    bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    vector<int> days = {31, isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    day++;
    if (day > days[m - 1]) {
        day = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    char res[9];
    snprintf(res, sizeof(res), "%04d%02d%02d", y, m, day);
    return string(res);
}

void solve() {
    int n;
    cin >> n;
    vector<char> type(n);
    vector<string> date(n);
    vector<char> time(n);
    vector<string> ans(n, "");
    for (int i = 0; i < n; ++i) {
        cin >> type[i] >> date[i] >> time[i];
    }

    unordered_map<string, unordered_map<char, int>> occ;
    queue<int> q;
    for (int i = 0; i < n; ++i) q.push(i);

    while (!q.empty()) {
        int i = q.front(); q.pop();
        string d = date[i];
        char t = time[i];
        char tp = type[i];
        while (true) {
            if (!occ[d].count(t)) {
                occ[d][t] = i;
                ans[i] = d;
                break;
            }
            int j = occ[d][t];
            if (get_pri(tp) > get_pri(type[j])) {
                occ[d][t] = i;
                date[j] = next_day(d);
                q.push(j);
                ans[i] = d;
                break;
            } else {
                d = next_day(d);
            }
        }
    }

    for (string& s : ans) cout << s << '\n';
}
int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596594.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}