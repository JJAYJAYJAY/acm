//
// Created by lyh on 2025/4/9.
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int get_mex(const vector<int>& a) {
    unordered_set<int> elements(a.begin(), a.end());
    int mex = 0;
    while (elements.count(mex)) mex++;
    return mex;
}

bool is_right(const vector<int>& a, int k, int x) {
    int n = a.size();
    unordered_set<int> required;
    for (int i = 0; i < x; i++) required.insert(i);

    int count = 0;
    unordered_set<int> current;
    int left = 0;
    for (int right = 0; right < n; right++) {
        if (a[right] < x) current.insert(a[right]);
        if (current.size() == required.size()) {
            count++;
            current.clear();
            left = right + 1;
        }
    }
    return count >= k;
}

int solve(const vector<int>& a, int k) {
    int mex = get_mex(a);
    int low = 0, high = mex;
    int answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_right(a, k, mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a, k) << '\n';
    }

    return 0;
}