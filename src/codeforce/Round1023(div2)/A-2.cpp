#include <iostream>
#include "vector"
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        mx = max(mx,x);
        mn = min(mn,x);
    }
    if(mx==mn){
        cout<<"No"<<endl;
        return;
    }else{
        cout<<"Yes"<<endl;
        for(int i=0;i<n;i++){
            if(a[i]==mx){
                cout<<1<<" ";
            }else{
                cout<<2<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1023(div2)/in/A.in", "r", stdin);
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