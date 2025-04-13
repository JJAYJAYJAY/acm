#include <iostream>
#include "algorithm"
#include "unordered_map"
#include "vector"
using namespace std;


string smallestPalindrome(string s, int k) {
    int len = s.length();
    string s1 = s.substr(0, len / 2);
    string s2 = s.substr(len - len / 2);
    vector<char> possible;
    unordered_map<char, int> m;
    for(int i=0;i<len;i++){
        m[s[i]]++;
    }
    for(auto it = m.begin();it!=m.end();it++){
        if(it->second%2==1){
            it->second--;
        }
        while(it->second > 0){
            it->second-=2;
            possible.push_back(it->first);
        }
    }
    sort(possible.begin(), possible.end());
    int l = possible.size();
    string ans;
}

void solve() {

}

int main() {
#ifdef LOCAL
    freopen("src/Leetcode/445/in/100619.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}