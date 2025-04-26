#include <iostream>
#include <vector>
using namespace std;

int n,m;
void solve() {
    cin >> n >> m;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    if (m == 1) {
        cout << -1 << '\n';
        return;
    }
    if(m == 1 || (m % 2 == 1 && n % 2 == 0)){
        cout << -1 << "\n";
        return;
    }
    int i = 1, j = n;
    vector<vector<int>> ans;
    while(i+m/2<=j-m/2) {
        vector <int> temp;
        for (int t = 0; t < m / 2; t++) {
            temp.push_back(i+t);
        }
        if (m % 2 == 1) {
            temp.push_back(1 + n / 2);
        }
        for (int t = 0; t < m / 2; t++) {
            temp.push_back(j-t);
        }
        ans.push_back(temp);
        i += m / 2;
        j -= m / 2;
    }
    if(i<j){
        vector <int> temp;
        for (int t = 0; t < m/2; t++) {
            temp.push_back(n/2-t);
        }

        if (m % 2 == 1) {
            temp.push_back(1 + n / 2);
            for(int t = 1; t <= m / 2; t++) {
                temp.push_back(n / 2 + 1 + t);
            }
        }else{
            for(int t = 0; t < m / 2; t++) {
                temp.push_back(n / 2 + 1 + t);
            }
        }
        ans.push_back(temp);
    }
    cout<<ans.size()<<endl;
    for(auto item:ans){
        for(auto item2:item){
            cout<<item2<<" ";
        }
        cout<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-222-Div2/in/T584084.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}