#include <iostream>
#include <string>

bool allItems(int l, int r) {
    int items = 0;
    for (int i = l; i <= r; ++i) {
        std::string item = std::to_string(i);
        for (char c : item) {
            items |= 1 << (c - '0');
        }
        if (items == 0b1111111111) return true;
    }
    return false;
}

//int main() {
//    int T;
//    std::cin >> T;
//    while (T--) {
//        int l, r;
//        std::cin >> l >> r;
//        std::cout << (allItems(l, r) ? "Yes" : "No") << std::endl;
//    }
//    return 0;
//}

