#include "iostream"
#include "cstring"

using namespace std;

int main(){
    int d,g;
    cin>>d>>g;
    int t[g+1],f[g+1],h[g+1];
    t[0]=0;
    f[0]=0;
    h[0]=0;
    for (int i=1;i<=g;i++){
        cin>>t[i]>>f[i]>>h[i];
    }

    for(int i=1;i<=g;i++){
        for(int j=i+1;j<=g;j++){
            if(t[i]>t[j]){
                swap(t[i],t[j]);
                swap(f[i],f[j]);
                swap(h[i],h[j]);
            }
        }
    }


    int dp[101][1001];
    memset(dp,-1,sizeof(dp));
    dp[0][0]=10;

    if(g==1){
        if(dp[0][0] - t[1]>=0 && h[1]>=d){
            cout<<t[1];
            return 0;
        }
    }

    for(int i=1;i<g;i++){
        for(int j=0;j<=d;j++){
            if(dp[i-1][j] >= t[i] - t[i - 1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j]+f[i]- (t[i] - t[i - 1]));
            }
            if(h[i]<=j && dp[i-1][j-h[i]] >= t[i] - t[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] - (t[i] - t[i - 1]));
            }
            if(dp[i][j]-(t[i+1] - t[i]) >=0 && j+h[i+1]>=d){
                cout<<t[i+1];
                return 0;
            }
        }
    }


    int ans=10,now=10;
    for(int i=1;i<=g;i++){
        if(now-(t[i]-t[i-1])>=0) {
            now -= (t[i]-t[i-1]);
            now += f[i];
            ans += f[i];
        }
        else{
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}