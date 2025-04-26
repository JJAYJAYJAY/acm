#include <iostream>
#include "cstring"
#include<vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<pair<pair<int,int>,long long>> last;
    long long mx=-1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t = s[j]-'0';

            if(i==j){
                t^=1;
            }
            if(t==1){

            }else{

            }
        }

    }
    if(mx==-1e9) {
        cout << 0 << endl;
    }else{
        cout << mx << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1020(div3)/in/F.in", "r", stdin);
#endif
    int work = 1;
    cin >> work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}