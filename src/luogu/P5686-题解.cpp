#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5,mod=1e9+7;
ll n,a[maxn],b[maxn],A[maxn],B[maxn],SA[maxn],SB[maxn],SAB[maxn],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],A[i]=(A[i-1]+a[i])%mod;
    for(int i=1;i<=n;i++) cin>>b[i],B[i]=(B[i-1]+b[i])%mod;
    for(int i=1;i<=n;i++) SA[i]=(SA[i-1]+A[i])%mod,SB[i]=(SB[i-1]+B[i])%mod,SAB[i]=(SAB[i-1]+(A[i]*B[i])%mod)%mod;
    for(int i=1;i<=n;i++) ans=(ans+((SAB[n]-SAB[i-1])+mod)%mod)%mod;
    for(int i=1;i<=n;i++) ans=(ans+(((n-i+1)*A[i-1])%mod*B[i-1])%mod)%mod;
    for(int i=1;i<=n;i++) ans=((ans-(B[i-1]*((SA[n]-SA[i-1]+mod)%mod))%mod)+mod)%mod;
    for(int i=1;i<=n;i++) ans=((ans-(A[i-1]*((SB[n]-SB[i-1]+mod)%mod))%mod)+mod)%mod;
    cout<<ans;
}