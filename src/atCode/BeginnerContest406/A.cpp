#include <iostream>

using namespace std;

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c>a){
        cout<<"No"<<endl;
        return;
    }
    if(c==a){
        if(d>b){
            cout<<"No"<<endl;
            return;
        }
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginnerContest406/in/A.in", "r", stdin);
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