#include <iostream>

using namespace std;

void solve() {
    int x,y,k;
    cin>>x>>y>>k;
    double l = k%(x+y)+0.5;

    if(l>=x){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1012(Div2)/in/A.in", "r", stdin);
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