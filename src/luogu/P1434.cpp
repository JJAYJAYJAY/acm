//
// Created by lyh on 2024/10/30.
//
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
struct Point{
    int x,y,v;
    bool operator<(const Point &p) const{
        return v<p.v;
    }
};
int cmp(const void *a,const void *b){
    return (*(Point*)a).v-(*(Point*)b).v;
}

int main(){
    int n,m;
    cin>>n>>m;
    Point map[n][m];
    Point arr[n*m];
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int idx = i * m + j;
            cin >> arr[idx].v;
            arr[idx].x = i;
            arr[idx].y = j;
            map[i][j] = arr[idx];
            dp[i][j] = 1;
        }
    }
    sort(arr,arr+n*m);
    for(int i=0;i<n*m;i++){
        int x=arr[i].x;
        int y=arr[i].y;
        if(x>0 && map[x-1][y].v>map[x][y].v){
            dp[x-1][y]=max(dp[x-1][y],dp[x][y]+1);
        }
        if(x<n-1 && map[x+1][y].v>map[x][y].v){
            dp[x+1][y]=max(dp[x+1][y],dp[x][y]+1);
        }
        if(y>0 && map[x][y-1].v>map[x][y].v){
            dp[x][y-1]=max(dp[x][y-1],dp[x][y]+1);
        }
        if(y<m-1 && map[x][y+1].v>map[x][y].v){
            dp[x][y+1]=max(dp[x][y+1],dp[x][y]+1);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
}