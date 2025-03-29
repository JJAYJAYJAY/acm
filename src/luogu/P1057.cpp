//
// Created by lyh on 2024/11/1.
//
#include "iostream"
#include "cstring"

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[2][1]=1;
    dp[n][1]=1;
    for(int j=2;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[i-1==0?n:i-1][j-1]+dp[i==n?1:i+1][j-1];
        }
    }
    cout<<dp[1][m];
}