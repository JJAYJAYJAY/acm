#include <iostream>
#include "cstring"
#include<vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<long long> a(n+1,0),b(n+1,0);
    long long mx=-1e9;
    s.insert(0," ");
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            a[i]=b[i-1]+1;
        }else{
            b[i]=b[i-1]+(n-i);
            a[i]=a[i-1]+(i-1);
        }
        mx = max(mx,max(a[i],b[i]));
//        cout<<a[i]<<" "<<b[i]<<endl;
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