#include <iostream>
#include<set>
using namespace std;

void solve() {
    int n;
    cin>>n;
    set<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    cout<<a.size()<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1019(div2)/in/A.in", "r", stdin);
#endif
    int work;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}