#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],dp[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i],dp[i-1]+arr[i]);
    }
    int ans=-0x7f7f7f7f;
    for(int i=1;i<n;i++){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    cout<<ans;
}