#include <iostream>

using namespace std;
int t;
void solve() {
cin>>t;
while(t--){
    int x;
    cin>>x;
    if(x%2==0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/A.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}