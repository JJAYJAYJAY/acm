//
//// Created by lyh on 2023/12/17.
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include "cmath"
//const int MOD = 998244353;
//
//using namespace std;
//int main() {
//    int n, k;
//      cin >> n >> k;
//      vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//          cin >> a[i];
//    }
//    sort(a.begin(), a.end());
//    int res=0;
//    for(int i=0;i<a.size();i++) {
//       for(int j=i;j<a.size();j++){
//           if(i-j==0){
//               res+=pow(a[j],k)*a[i];
//           } else {
//               res += pow(a[j], k) * a[i] * (j - i);
//           }
//       }
//    }
//    cout<<res%MOD;
//    return 0;
//}




#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353
using namespace std;

long long quickPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    sort(a.begin(), a.end());
//    long long res = 0;
//    long long max;
//    long long min=0;
//    for (int i = 0; i < n; ++i) {
//        max=quickPow(a[i],k) % MOD;
//        res=(res+(max*(min+a[i])%MOD))% MOD;
//        min=(min*2+a[i]) % MOD;
//    }
//    cout << res;
//    return 0;
//}