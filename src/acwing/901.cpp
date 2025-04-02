//
// Created by lyh on 2025/4/1.
//
#include <iostream>

using namespace std;
const int N =90010;
int dp[310][310];
int mp[310][310];
int n,m;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int dfs(int x,int y){
    if(dp[x][y]) return dp[x][y];

    dp[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x+dx[i],ny = y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]>mp[x][y]){
            dp[x][y] = max(dp[x][y],dfs(nx,ny)+1);
        }
    }
    return dp[x][y];
}

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans = max(ans,dfs(i,j));
        }
    }
    cout<<ans;
}