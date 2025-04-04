//
// Created by lyh on 2025/4/4
//

#include <iostream>
#include "cmath"
using namespace std;
const int N = 1e5+10;
int n,k;
int a[N];
int dp[N][21];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

void ST_init(){
    for(int i=1;i<=n;i++){
        dp[i][0] = a[i];
    }
    int t = log(n)/log(2)+1;
    for(int j=1;j<t;j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("src/luogu/P3000-P4000/in/P3865.in","r",stdin);
#endif
    n = read();
    k = read();
    for(int i=1;i<=n;i++) {
        a[i] = read();
    }
    ST_init();
    while(k--) {
        int l = read();
        int r = read();
        int t = log(r-l+1)/log(2);
        printf("%d\n",max(dp[l][t],dp[r-(1<<t)+1][t]));
    }

#ifdef LOCAL
    fclose(stdin);
#endif
}