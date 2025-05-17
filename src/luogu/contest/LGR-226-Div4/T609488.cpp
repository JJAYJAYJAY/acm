#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<bool> st(n+1, false);
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        st[x]=true;
    }

    for(int i=0;i<k;i++){
        bool flag= false;
        for(int j=0;j<n/k;j++){
            int x;
            cin>>x;
            if(flag){
                if(st[x]){
                    cout<<"\\QAQ/"<<endl;
                    return;
                }
            }else{
                if(st[x]){
                   flag = true;
                }
            }
        }
    }
    cout<<"\"MiaoW\""<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-226-Div4/in/T609488.in", "r", stdin);
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