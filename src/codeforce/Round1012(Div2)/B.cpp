#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    if(n==1||m==1){
        cout<<"Yes"<<endl;
        return;
    }
    vector<vector<int>> l(n, vector<int>(m, 0));
    vector<vector<int>> t(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        if(s[i][0]=='1'){
            l[i][0]=1;
        }
    }
    for(int i=0;i<m;i++){
        if(s[0][i]=='1'){
            t[0][i]=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(s[i][j]=='1'){
                if(l[i][j-1]){
                    l[i][j]=1;
                }
                if(t[i-1][j]){
                    t[i][j]=1;
                }
                if(l[i][j]==0&&t[i][j]==0){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1012(Div2)/in/B.in", "r", stdin);
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