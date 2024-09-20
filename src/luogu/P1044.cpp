//
// Created by lyh on 2024/9/19.
//
#include "iostream"
#include "cstring"
int main(){
    int n;
    scanf("%d",&n);
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) {
        dp[i][0] = 1;
    }
    for(int j=1;j<=n;j++){
        for(int i=0;i<=n;i++){
            if(i>0){
                dp[i][j]=dp[i-1][j]+dp[i+1][j-1];
            }
            if(i==0){
                dp[i][j]=dp[i+1][j-1];
            }
        }
    }
    printf("%d",dp[0][n]);
}