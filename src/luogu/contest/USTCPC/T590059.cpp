//
// Created by lyh on 2025/4/5.
//
#include<iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    string result = "NOT FOUND";
    size_t n = s.length();

    for (size_t i = 0; i + 5 < n; ++i) {
        if (s.substr(i, 5) == "flag{") {
            size_t j = i + 5;
            bool valid = true;
            while (j < n) {
                if (s[j] == '}') {
                    result = s.substr(i, j - i + 1);
                    cout << result << endl;
                    return 0;
                } else if (s[j] == '{' || s[j] == '}') {
                    valid = false;
                    break;
                }
                ++j;
            }
            if (!valid) {
                continue;
            }
        }
    }

    cout << result << endl;
    return 0;
}