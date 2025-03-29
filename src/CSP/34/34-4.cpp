//
// Created by lyh on 2025/3/29.
//
#include<iostream>
#include <vector>
#include<set>
#include<cstring>
using namespace std;
const int N=1e4+10;
const int M = 40000;
int v,n,m,b[N],c[N];
multiset<int,greater<int>> s[N];

int dp[N][M];
int main(){
    scanf("%d%d%d",&n,&m,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&b[i],&c[i]);
    }
    for(int i=1;i<=m;i++){
        int a,t;
        scanf("%d%d",&a,&t);
        s[t+1].insert(a);
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<M;j++){
            dp[i][j]=dp[i-1][j];
            int cost=b[i];
            int money=0;
            auto it = s[i].begin();
            for(int k=0;k<s[i].size();k++){
                if(j>=cost+c[i]){
                    cost+=c[i];
                    money+=*it;
                    dp[i][j]=max(dp[i-1][j-cost]+money-cost,dp[i][j]);
                    it++;
                }else{
                    break;
                }
            }
        }
    }

    for(int i=0;i<M;i++){
        if(dp[n][i]>=v){
            cout<<i<<endl;
            break;
        }
    }
}

