#include <iostream>
#include "algorithm"
using namespace std;

string smallestPalindrome(string s) {
    int len = s.length();
    string s1=s.substr(0, len / 2);
    string s2 = s.substr(len - len / 2);
    string ans;
    //将s1的内容排序
    sort(s1.begin(), s1.end());
    //将s2的内容排序
    sort(s2.begin(), s2.end(), greater<char>());
    ans = s1;
    if(len % 2 == 1) {
        ans += s[len / 2];
    }
    ans+= s2;
    return ans;
}

void solve() {
    string s;
    cin >> s;
    cout << smallestPalindrome(s) << endl;
}

int main() {
#ifdef LOCAL
    freopen("src/Leetcode/445/in/100618.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}