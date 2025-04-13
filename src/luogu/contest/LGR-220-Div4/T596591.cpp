#include <iostream>

using namespace std;


void solve() {
    int n,m;
    int cnt=0;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%m==0){
            continue;
        }
        int t = x;
        int a=0;
        while(x){
            a+=x%10;
            x/=10;
        }
        if(a%m==0){
            cout<<t<<endl;
            cnt++;
        }
    }
    if(cnt==0){
        cout<<"None"<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596591.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}