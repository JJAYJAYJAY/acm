#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
vector<string> split(const string& s) {
    vector<string> ss;
    string now;
    for (char c : s) {
        now += c;
        if (c == '.' || c == '?' || c == '!') {
            ss.push_back(now);
            now.clear();
        }
    }
    if (!now.empty()) ss.push_back(now);
    return ss;
}

void calc(const string& s) {
    int cnt = 0;
    long long sum = 0;
    string num;
    for (char c : s) {
        if (isdigit(c)) num += c;
        else if (!num.empty()) {
            long long v = 0;
            for (char d : num) v = v * 10 + (d - '0');
            sum += v;
            cnt++;
            num.clear();
        }
    }
    if (!num.empty()) {
        long long v = 0;
        for (char d : num) v = v * 10 + (d - '0');
        sum += v;
        cnt++;
    }
    cout << cnt << " " << (sum % 2 == 0 ? "Even" : "Odd") << endl;
}

void solve() {
    string p;
    getline(cin, p);
    vector<string> ss = split(p);
    for (const string& s : ss) {
        calc(s);
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596593.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
return 0;
}