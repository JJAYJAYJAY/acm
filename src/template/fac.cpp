//
// Created by lyh on 25-5-6.
//
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
const int MAX = 5e5;
using ll = long long;
vector<ll> fac(MAX+1), ifac(MAX+1);

// 快速幂
ll modpow(ll a, ll e=MOD-2){
    ll r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD; e>>=1;
    }
    return r;
}


int main(){
    fac[0]=1;
    for(int i=1;i<=MAX;i++) fac[i]=fac[i-1]*i%MOD;
    ifac[MAX]=modpow(fac[MAX]);
    for(int i=MAX;i>0;i--) ifac[i-1]=ifac[i]*i%MOD;
}