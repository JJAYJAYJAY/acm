//
// Created by lyh on 2024/10/30.
//
#include <cstring>
#include "iostream"

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
    }
    for(int i=1;i<=m;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i%2==0 && j%2==0){
                dp[i][j]=0;
            } else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n][m];
}