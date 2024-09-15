//
// Created by lyh on 2023/12/17.
//
//#include <iostream>
//#include <vector>
//using namespace std;
//const int NUM = 1000;
//int p[NUM];
//
//int find(int x) {
//    if (p[x] != x) p[x] = find(p[x]);
//    return p[x];
//}
//void init(int n){
//    for (int i = 1; i <= n; i++) p[i] = i;
//}
//
//int main() {
//    int n, m, q;
//    cin >> n >> m >> q;
//    init(n);
//    for (int i = 1; i <= m; i++) {
//        vector<int> a(n + 1), b(n + 1);
//        for (int j = 1; j <= n; j++) {
//            cin >> a[j];
//            b[a[j]] = j;
//        }
//        for (int j = 1; j <= n; j++) {
//            int x = find(j), y = find(b[j]);
//            if (x != y) p[x] = y;
//        }
//    }
//    for(int i=0;i<q;i++) {
//        int x, y;
//        cin >> x >> y;
//        if (find(x) == find(y)) cout<<"yes";
//        else cout<<"no";
//    }
//    return 0;
//}



