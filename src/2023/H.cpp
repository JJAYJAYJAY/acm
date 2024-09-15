//
// Created by lyh on 2023/12/17.
//
//#include "iostream"
//const int MOD = 1e9+7;
//using namespace std;
//
//void moves(int x,int y,int& cnt,int value,int k,int** a){
//    value*=a[x][y];   
//    if(value>=k){
//        cnt++;
//    }
//    if(x!=0) {
//        moves(x - 1, y, cnt, value, k, a);
//    }
//    if(y!=0) {
//        moves(x, y - 1, cnt, value, k, a);
//    }
//}
//
//int main(){
//    int n,m,k;
//    cin>>n>>m>>k;
//    int **a=new int * [n];
//    for(int i = 0; i < n; ++i)
//        a[i] = new int[m];
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> a[i][j];
//        }
//    }
//    int cnt=0;
//    moves(n-1,m-1,cnt,1,k,a);
//    cout<<cnt%MOD;
//}

//#include <iostream>
//#include <vector>
//
//const int MOD = 1e9+7;
//using namespace std;
//int main() {
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<vector<int>> a(n, vector<int>(m));
//    vector<vector<int>> b(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> a[i][j];
//        }
//    }
//    vector<vector<int>> dp(n, vector<int>(m));
//    dp[0][0] = a[0][0];
//    for (int i = 1; i < n; ++i) {
//        dp[i][0] = dp[i - 1][0] * a[i][0];
//    }
//    for (int j = 1; j < m; ++j) {
//        dp[0][j] = dp[0][j - 1] * a[0][j];
//    }
//
//    for (int i = 1; i < n; ++i) {
//        for (int j = 1; j < m; ++j) {
//            if(dp[i-1][j]*a[i][j]>=k){
//                if(b[i-1][j]!=0)
//                    b[i][j]+=b[i-1][j];
//                else
//                    b[i][j]+=1;
//                dp[i][j]=dp[i - 1][j]* a[i][j];
//            }
//            if(dp[i][j-1]*a[i][j]>=k){
//                if(b[i-1][j]!=0)
//                    b[i][j]+=b[i][j-1];
//                else
//                    b[i][j]+=1;
//                dp[i][j]=dp[i][j-1]* a[i][j];
//            }
//            if(dp[i][j]==0)
//                dp[i][j]=min(dp[i][j-1],dp[i-1][j])*a[i][j];
//        }
//    }
//    int cnt = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout<<b[i][j];
//            cnt+=b[i][j];
//        }
//        cout<<endl;
//    }
//    cout << cnt % MOD << endl;
//    return 0;
//}