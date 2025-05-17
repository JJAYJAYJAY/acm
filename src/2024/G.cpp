#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<2*n-1;i++){
        int x;
        cin >> x;
        if(s.count(x)){
            s.erase(x);
        }else{
            s.insert(x);
        }
    }
    cout<<*s.begin()<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/2024/in/G.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}