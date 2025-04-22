#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        int total_xor = 0;
        for (auto [x, y] : points) {
            int xp = (x % 2 + 2) % 2;
            int yp = (y % 2 + 2) % 2;
            int code = (xp << 1) | yp;
            total_xor ^= code;
        }

        int sp = (total_xor >> 1) & 1;
        int tp = total_xor & 1;

        pair<int, int> ans;
        bool found = false;
        for (auto [x, y] : points) {
            int xp = (x % 2 + 2) % 2;
            int yp = (y % 2 + 2) % 2;
            if (xp == sp && yp == tp) {
                ans = {x, y};
                found = true;
                break;
            }
        }

        if (!found) {
            int x = points[0].first;
            int y = points[0].second;
            int xp = (x % 2 + 2) % 2;
            int yp = (y % 2 + 2) % 2;

            int dx = (sp - xp) % 2;
            if (dx < 0) dx += 2;
            int dy = (tp - yp) % 2;
            if (dy < 0) dy += 2;

            // Adjust dx and dy to prefer negative increments when applicable
            if (dx == 1 && xp == 1) {
                dx = -1;
            } else {
                dx = dx;
            }

            if (dy == 1 && yp == 1) {
                dy = -1;
            } else {
                dy = dy;
            }

            ans = {x + dx, y + dy};
        }

        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}