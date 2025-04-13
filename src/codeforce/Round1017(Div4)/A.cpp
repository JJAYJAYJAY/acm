#include <iostream>

using namespace std;
int t;
void solve() {
    cin>>t;
    while(t--){
        string ans;
        for(int i=0;i<3;i++){
            string s;
            cin>>s;
            ans+=s[0];
        }
        cout<<ans<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/A.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}