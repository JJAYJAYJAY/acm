//
// Created by lyh on 2025/4/5.
//
#include <iostream>
#include "cmath"
using namespace std;
const int N =2e5+10;
long long t;
int m,mod;
long long dp[N][21];
int idx;

void change(long long x){
    dp[++idx][0] = x;
    for(int i=1;idx-(1<<i)>=0;i++){
        dp[idx][i] = max(dp[idx][i-1],dp[idx-(1<<(i-1))][i-1]);
    }
}

long long find(int x,int y){
    int k = (int)log2(y-x+1);
    return max(dp[y][k],dp[x+(1<<k)-1][k]);
}

int main(){
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1198.in","r",stdin);
#endif
    scanf("%d%d",&m,&mod);
    while(m--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(op[0] == 'A'){
            change((x+t)%mod);
        }else{
            if(x==1){
                printf("%lld\n",dp[idx][0]);
                t = dp[idx][0];
                continue;
            }
            t = find(idx-x+1,idx);
            printf("%lld\n",t);

        }
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}