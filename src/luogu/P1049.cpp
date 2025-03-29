//
// Created by lyh on 2024/11/1.
//
#include "iostream"
#include "cstring"
using namespace std;
int main(){
    int v;
    cin>>v;
    int n;
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int dp[n+1][v+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=v;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
            }
        }
    }
    cout<<v-dp[n][v];
}