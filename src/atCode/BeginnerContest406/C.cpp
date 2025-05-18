#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    vector<int> p(n+1);
    for(int i=1;i<n;i++){
        p[i]=(a[i]>a[i-1])?1:0;
    }
    vector<int> b;
    for(int i=2;i<n;i++){
        if(p[i]!=p[i-1]){
            b.push_back(i);
        }
    }
    long long res = 0;
    int x = 0;
    for(int i=1;i<n;i++){
        if(p[i]!=1) continue;
        while(x<b.size()&&b[x]<=i){
            x++;
        }
        if(x+1>=b.size()) {
            break;
        }
        int i2 = b[x + 1];
        int i3 = (x + 2 < b.size() ? b[x + 2] : n);
        if(i2 < i3){
            res += (i3 - i2);
        }
    }
    cout<<res<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginnerContest406/in/C.in", "r", stdin);
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