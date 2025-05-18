#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    bool flag = false;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            flag=true;
        }
    }

    for(int i=1;i<n;i++){
        if(a[i]==0&&a[i+1]==0){
            cout<<"Yes"<<endl;
            return;
        }

    }
    if(!flag){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1025(Div2)/in/A.in", "r", stdin);
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