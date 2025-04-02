//
// Created by lyh on 2024/9/17.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;  // 测试组数
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);

        // 读取序列 a
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }



        cout << endl;
        int turn = 0;
        int bob_last = 0;
        int alice_last = 0;
        // 如果 a[0] == 0，Bob 获胜
        if (a[0] == 0 || a[0] == 1){
            cout << "Bob" << endl;
        }else {
            while(true){
                if (turn % 2 == 1) {
                    if(bob_last == a[0]||a[0]==0){
                        cout << "Alice" << endl;
                        break;
                    }
                    bob_last = a[0];
                } else {
                    if(alice_last == a[0]||a[0]==0){
                        cout << "Bob" << endl;
                        break;
                    }
                    alice_last = a[0];
                }
                //保留 0 ~ a[0] 的数,后面的删除
                a.resize(a[0]);
                //排序
                sort(a.begin(), a.end());
                turn++;
                
                //输出a

            }
        }
    }
    return 0;
}
