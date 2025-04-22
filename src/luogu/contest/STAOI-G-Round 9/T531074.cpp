#include <iostream>

using namespace std;
const int N=3010;
int dp[N];
int a[N];
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=0;
    dp[1]=1;
    if(a[2] == a[1]){
        dp[2] = 1;
    }else{
        dp[2] = 2;
    }
    for(int i=3;i<=n;i++){
        if(a[i] == a[i-1]){
            dp[i] = 1;
        }else{
            if(a[i] == a[i-2]) {
                dp[i] = dp[i-1]+1;
            }else{
                dp[i] = 2;
            }
        }
    }
    int maxx = 0;
    for(int i=1;i<=n;i++){
        maxx = max(maxx,dp[i]);
    }
    cout<<maxx<<endl;
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        a[x] = y;
        for(int i=x;i<=n;i++){
            if(i == 1){
                dp[i] = 1;
            }else if(i == 2){
                if(a[2] == a[1]){
                    dp[i] = 1;
                }else{
                    dp[i] = 2;
                }
            }else{
                if(a[i] == a[i-1]){
                    dp[i] = 1;
                }else{
                    if(a[i] == a[i-2]) {
                        dp[i] = dp[i-1]+1;
                    }else{
                        dp[i] = 1;
                    }
                }
            }
        }
        maxx = 0;
        for(int i=1;i<=n;i++){
            maxx = max(maxx,dp[i]);
        }
        cout<<maxx<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/STAOI-G-Round 9/in/T531074.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}