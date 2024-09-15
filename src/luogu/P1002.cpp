//ar
// Created by lyh on 2024/9/14.
//
#include "iostream"
using namespace std;
int main() {
    int b_x,b_y,c_x,c_y;
    cin>>b_x>>b_y>>c_x>>c_y;
    b_y++;
    b_x++;
    long long dp[b_x][b_y];
    dp[0][0]=1;
    //初始化
    for(int i=1;i<b_x;i++){
        if(
            i==c_x&&c_y==0||
            i==c_x-1&&c_y-2==0||
            i==c_x-2&&c_y-1==0||
            i==c_x+1&&c_y-2==0||
            i==c_x+2&&c_y-1==0
        ){
            dp[i][0]=0;
        } else{
            dp[i][0]=dp[i-1][0];
        }
    }
    for(int j=1;j<b_y;j++){
        if(
                j==c_y&&c_x==0||
                j==c_y-1&&c_x-2==0||
                j==c_y-2&&c_x-1==0||
                j==c_y+1&&c_x-2==0||
                j==c_y+2&&c_x-1==0
        ){
            dp[0][j]=0;
        } else{
            dp[0][j]=dp[0][j-1];
        }
    }
//    for(int i=0;i<b_x;i++){
//        for(int j=0;j<b_y;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i=1;i<b_x;i++){
        for(int j=1;j<b_y;j++){
            if(
                i==c_x&&j==c_y||
                i==c_x-1&&j==c_y-2||
                i==c_x-2&&j==c_y-1||
                i==c_x-1&&j==c_y+2||
                i==c_x-2&&j==c_y+1||
                i==c_x+1&&j==c_y-2||
                i==c_x+2&&j==c_y-1||
                i==c_x+1&&j==c_y+2||
                i==c_x+2&&j==c_y+1
            ){
                dp[i][j]=0;
            } else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[b_x-1][b_y-1];
//打印dp
//    for(int i=0;i<b_x;i++){
//        for(int j=0;j<b_y;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}