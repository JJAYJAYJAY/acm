//
// Created by lyh on 2024/10/28.
//
#include "iostream"

using namespace std;
#define MAXN 1005
int main(){
    int n,k;
    cin>>n>>k;
    int books[n];
    for(int i=0;i<n;i++){
        int index;
        cin>>index;
        cin>>books[i];
    }
    int dp[MAXN][MAXN]={0};
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-k;j++){
            dp[i];
        }
    }
}