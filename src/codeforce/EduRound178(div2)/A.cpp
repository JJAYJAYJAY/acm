#include <iostream>

using namespace std;

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)%3!=0) cout<<"NO"<<endl;
    else{
        int x = (a+b+c)/3;
        if(x<=c&&x>=a&&x>=b){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/EduRound178(div2)/in/A.in", "r", stdin);
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