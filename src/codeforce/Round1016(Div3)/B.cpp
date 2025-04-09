#include <iostream>

using namespace std;
int t;
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        string n;
        cin>>n;
        int len = n.length();
        int cnt = 0;
        int i=0,j=len-1;
        while(i<j){
            if(n[j]=='0'){
                cnt++;
                j--;
            }else{
                while(n[i]=='0'&& i<j){
                    i++;
                }
                if(i==j){
                    cnt--;
                }
                cnt++;
                i++;
            }
        }
        cout<<cnt<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/B.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}