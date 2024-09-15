#include <iostream>
#include <vector>
//
//int main() {
//    int n, q;
//    std::cin >> n >> q;
//    std::vector<int> a(n + 1), prefix(n + 1);
//    for (int i = 1; i <= n; ++i) {
//        std::cin >> a[i];
//        prefix[i] = prefix[i - 1] ^ a[i];
//    }
//    while (q--) {
//        int l, r;
//        std::cin >> l >> r;
//        std::cout<< (prefix[r] ^ prefix[l - 1]) << std::endl;
//    }
//    return 0;
//}
