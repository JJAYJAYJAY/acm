#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int target;
    cin>>target;
    int cnt=0;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        if(abs(x)<abs(target)) {
            cnt++;
        }
    }
    if(cnt>n/2){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1024(Div2)/in/B.in", "r", stdin);
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