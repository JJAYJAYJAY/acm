#include <iostream>
#include "vector"
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    int dx=0;
    for(int i=n;i>=1;i--){
        int idx = i-dx;
        idx = idx % n;
        if(idx<=0){
            idx = n+idx;
        }
        if(a[idx]!=0){
            cout<<"-1"<<endl;
            return;
        }
        a[idx]=i;
        dx++;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1013(Div3)/in/C.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}