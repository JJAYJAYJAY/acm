//
// Created by lyh on 2025/4/5.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contestant {
    int x;
    int y;
};

int main() {
    int g, s, b, h;
    cin >> g >> s >> b >> h;
    int total = g + s + b + h;
    vector<Contestant> contestants(total);
    for (int i = 0; i < total; ++i) {
        cin >> contestants[i].x >> contestants[i].y;
    }

    Contestant g_sup = contestants[g - 1];
    Contestant g_inf;
    if (g + s + b + h > g) {
        g_inf.x = contestants[g].x;
        g_inf.y = contestants[g].y - 1;
        if (g_inf.y < 0) {
            g_inf.x -= 1;
            g_inf.y = 180000;
        }
    } else {
        g_inf.x = 0;
        g_inf.y = 0;
    }

    Contestant s_sup = contestants[g + s - 1];
    Contestant s_inf;
    if (g + s + b + h > g + s) {
        s_inf.x = contestants[g + s].x;
        s_inf.y = contestants[g + s].y - 1;
        if (s_inf.y < 0) {
            s_inf.x -= 1;
            s_inf.y = 180000; // 假设最大罚时
        }
    } else {
        s_inf.x = 0;
        s_inf.y = 0;
    }

    Contestant b_sup = contestants[g + s + b - 1];
    Contestant b_inf;
    if (g + s + b + h > g + s + b) {
        b_inf.x = contestants[g + s + b].x;
        b_inf.y = contestants[g + s + b].y - 1;
        if (b_inf.y < 0) {
            b_inf.x -= 1;
            b_inf.y = 180000; // 假设最大罚时
        }
    } else {
        b_inf.x = 0;
        b_inf.y = 0;
    }

    cout << g_sup.x << " " << g_sup.y<< " " << g_inf.x << " " << g_inf.y << endl;
    cout << s_sup.x << " " << s_sup.y << " " << s_inf.x << " " << s_inf.y << endl;
    cout << b_sup.x << " " << b_sup.y << " " << b_inf.x << " " << b_inf.y << endl;

    return 0;
}