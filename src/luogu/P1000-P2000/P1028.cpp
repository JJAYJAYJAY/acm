//
// Created by lyh on 2024/9/19.
//
#include "iostream"
#include "cstring"
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[n]=1;
    for(int i=n-1;i>n/2;i--){
        dp[i]=0;
    }
    for(int i=n/2;i>0;i--){
        for(int j=i*2;j<=n;j++){
            dp[i]+=dp[j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i];
    }
    cout<<ans;
}