#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
int m,n;
int a[N];
int dp[N][21];

void solve() {
    memset(dp,0x3f3f3f3f,sizeof(dp));
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        dp[i][0] = a[i];
    }
    int t = (int)log2(m)+1;
    for(int j=1;j<=t;j++){
        for(int i=1;i+(1<<j)-1<=m;i++){
            dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        int k = (int)log2(y-x+1);
        printf("%d ",min(dp[x][k],dp[y-(1<<k)+1][k]));
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1816.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}