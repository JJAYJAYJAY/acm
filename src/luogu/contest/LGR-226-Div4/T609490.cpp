#include <iostream>

using namespace std;

void solve() {
    string s;
    cin>>s;
    if(s.length()%2==1){
        s="0"+s;
    }
    string ans="";
    for(int i=0;i<s.length();i+=2){
        ans=s.substr(i,2)+ans;
    }
    while(ans[0]=='0'){
        ans = ans.substr(1);
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-226-Div4/in/T609490.in", "r", stdin);
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