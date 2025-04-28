#include <iostream>

using namespace std;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s.insert(0," ");
    if(s[n]==s[1]){
        if(s[n]=='A'){
            cout<<"Alice"<<endl;
            return;
        }else{
            cout<<"Bob"<<endl;
            return;
        }
    }
    if(s[n]=='A'&&s[1]=='B'){
        if(s[n-1]=='A'){
            cout<<"Alice"<<endl;
            return;
        }else{
            cout<<"Bob"<<endl;
            return;
        }
    }
    if(s[n]=='B'&&s[1]=='A'){
        for(int i=1;i<=n-1;i++){
            if(s[i]=='B'){
                cout<<"Bob"<<endl;
                return;
            }
        }
        cout<<"Alice"<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound178(div2)/in/C.in", "r", stdin);
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