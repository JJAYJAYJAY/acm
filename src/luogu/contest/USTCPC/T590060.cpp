//
// Created by lyh on 2025/4/5.
//
#include<iostream>

using namespace std;
const int N =  21;
int t;

long long memo[N];

//斐波那契数列

long long fib(int n) {
    if (n == 0) return memo[0] = 0;
    if (n <= 2) return memo[n] = 1;
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main(){
#ifdef LOCAL
    freopen("src/luogu/contest/USTCPC/in/T590060.in","r",stdin);
#endif
    fib(20);
    scanf("%d",&t);
    while(t--){
        long long a,x,b;
        scanf("%lld%lld%lld",&a,&x,&b);
        if((x-memo[a-1])%memo[a] !=0){
            printf("-1\n");
        }else{
            long long p = (x-memo[a-1])/memo[a];
            long long ans = memo[b]*p+memo[b-1];
            printf("%lld\n",ans);
        }
    }

#ifdef LOCAL
    fclose(stdin);
#endif
}