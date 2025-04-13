#include <iostream>

using namespace std;
int t;

bool check(const string& p, const string& s, int i, int j) {
    if (i == p.size() && j == s.size()) {
        return true;
    }
    if (i >= p.size() || j >= s.size()) {
        return false;
    }
    if (p[i] != s[j]) {
        return false;
    }
    if (check(p, s, i + 1, j + 1)) {
        return true;
    }
    if (j + 1 < s.size() && s[j + 1] == p[i]) {
        if (check(p, s, i + 1, j + 2)) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin>>t;
    while(t--){
        string s,p;
        cin>>p>>s;
        if(s.length()>2*p.length()){
            cout<<"NO"<<endl;
            continue;
        }
        if(check(p, s, 0, 0)){
            cout<<"YES"<<endl;
            continue;
        }else{
            cout<<"NO"<<endl;
            continue;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/D.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}