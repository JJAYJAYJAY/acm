#include <iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n%2==0){
        cout<<-1<<endl;
        return;
    }
    cout<<n<<" ";
    for(int i=2;i<=n;i++){
        cout<<i-1<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1015(Div1+Div2)/in/A.in", "r", stdin);
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