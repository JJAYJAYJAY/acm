#include <iostream>
#include <cstring>

using namespace std;

const int N =1010;

int w[N],h[N];
int dp[N][2010];
int tr[N][2];
int cnt=1;
int n;
void read(int x){
    int a,b;
    cin>>a>>b;
    w[x] = a;
    if(b==0){
        tr[x][0] = ++cnt;
        read(cnt);
        tr[x][1] = ++cnt;
        read(cnt);
    }else{
        h[x] = b;
        dp[x][0] = 0;
        for(int i=1;i<=h[x];i++){
            dp[x][i] = 2*w[x]+i*5;
        }
//        for(int i=2*w[x];i<=n-1;i++){
//            dp[x][i] = min((i-2*w[x])/5,h[x]);
//        }
    }
}


void dfs(int x){
    if(h[x]!=0){
        return;
    }else{
        dfs(tr[x][0]);
        dfs(tr[x][1]);
        for(int i=0;i<=h[tr[x][0]]+h[tr[x][1]];i++){
            if(i==0){
                dp[x][i] = 0;
                continue;
            }
            for(int l = max(i-h[tr[x][1]],0);l<=min(h[tr[x][0]],i);l++){
                dp[x][i] = min(dp[x][i],dp[tr[x][0]][l] + dp[tr[x][1]][i-l] + 2*w[x]);
            }
            h[x]=h[tr[x][0]]+h[tr[x][1]];
        }
//        for(int i=2*w[x];i<=n;i++){
//            for(int l = 0;l<=i-2*w[x]; l++){
//                dp[x][i] = max(dp[x][i],dp[tr[x][0]][l] + dp[tr[x][1]][i-l-2*w[x]]);
//            }
//        }
    }
}

void solve() {
    cin>>n;
    n--;
    memset(dp,0x3f,sizeof(dp));
    read(1);
    dfs(1);
    for(int i=2000;i>=0;i--){
        if(dp[1][i]<=n-1){
            cout<<i<<endl;
            return;
        }
    }
//    cout<<dp[1][n-1]<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1270.in","r",stdin);
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