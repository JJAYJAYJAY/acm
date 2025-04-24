#include <iostream>

using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;
    for(int i=0;i<x;i++){
        cout<<i<<" ";
    }
    for(int j=n-1;j>=x;j--){
        cout<<j<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1020(div3)/in/B.in", "r", stdin);
#endif
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}