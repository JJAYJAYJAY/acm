//
// Created by lyh on 2025/3/28.
//
#include <iostream>

using namespace std;
const int N = 1e6+10;
int n,m,k;
int dp[N];
int ans[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    while(n--){
        int t,c;
        scanf("%d%d",&t,&c);
        dp[max(1,t-k-c+1)]++;
        dp[max(1,t-k+1)]--;
    }
    for(int i=1;i<N;i++){
        ans[i]= ans[i-1]+dp[i];
    }

    while(m--){
        int q;
        scanf("%d",&q);
        printf("%d\n",ans[q]);
    }
}
