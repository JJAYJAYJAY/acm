#include <iostream>

using namespace std;
int t;
void solve() {
    cin >> t;
    while(t--){
        int n,m,l,r;
        cin >> n >> m >> l >> r;
        int s = n-m;
        while(s){
            if(l){
                l++;
                s--;
                if(!s) break;
            }
            if(r){
                r--;
                s--;
                if(!s) break;
            }
        }
        cout << l << " " << r<< endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/B.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}