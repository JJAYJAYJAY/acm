#include <iostream>
#include<map>
#include<vector>
#include<unordered_set>
using namespace std;
const int MOD = 1e9 + 7;
using ll =long long;

//void solve() {
//    int n,m,k;
//    cin>>n>>m>>k;
//    vector<pair<int,int>> a(k+1);
//    for(int i=0;i<k+1;i++){
//        int x,y;
//        cin>>x>>y;
//        a[i].first=x;
//        a[i].second=y;
//    }
//    vector<long long> dp(k+1,0);
//    map<pair<int,int>,long long> mp;
//    dp[0]=1;
//    for(int i=1;i<k+1;i++){
//        int dx = a[i].first-a[i-1].first;
//        int dy = a[i].second-a[i-1].second;
//
//        if(dx==0||dy==0){
//            if(dx==2){
//                dp[i] = (dp[i-1]-mp[{a[i-1].first+1,a[i-1].second}])%MOD;
//                int t = mp[{a[i-1].first+1,a[i-1].second}];
//                for(auto item:mp){
//                    mp[{item.first.first,item.first.second}]=item.second-t<0?item.second-t+MOD:item.second-t;
//                }
//                mp[{a[i-1].first+1,a[i-1].second}]=dp[i];
//            }
//            if(dx==-2){
//                dp[i] = (dp[i-1]-mp[{a[i-1].first-1,a[i-1].second}])%MOD;
//                int t = mp[{a[i-1].first-1,a[i-1].second}];
//                for(auto item:mp){
//                    mp[{item.first.first,item.first.second}]=item.second-t<0?item.second-t+MOD:item.second-t;
//                }
//                mp[{a[i-1].first-1,a[i-1].second}]=dp[i];
//            }
//            if(dy==2){
//                dp[i] = (dp[i-1]-mp[{a[i-1].first,a[i-1].second+1}])%MOD;
//                int t = mp[{a[i-1].first,a[i-1].second+1}];
//                for(auto item:mp){
//                    mp[{item.first.first,item.first.second}]=item.second-t<0?item.second-t+MOD:item.second-t;
//                }
//                mp[{a[i-1].first,a[i-1].second+1}]=dp[i];
//            }
//            if(dy==-2){
//                dp[i] = (dp[i-1]-mp[{a[i-1].first,a[i-1].second-1}])%MOD;
//                int t = mp[{a[i-1].first,a[i-1].second-1}];
//                for(auto item:mp){
//                    mp[{item.first.first,item.first.second}]=item.second-t<0?item.second-t+MOD:item.second-t;
//                }
//                mp[{a[i-1].first,a[i-1].second-1}]=dp[i];
//            }
//        }else{
//            if(dx==1&&dy==1){
//                dp[i] = (dp[i-1]*2-mp[{a[i-1].first+1,a[i-1].second}]-mp[{a[i-1].first,a[i-1].second+1}])%MOD;
//                if(mp[{a[i-1].first+1,a[i-1].second}]==0){
//                    mp[{a[i-1].first+1,a[i-1].second}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first+1,a[i-1].second}]=(mp[{a[i-1].first+1,a[i-1].second}]+dp[i-1]-mp[{a[i-1].first+1,a[i-1].second}])%MOD;
//                }
//                if(mp[{a[i-1].first,a[i-1].second+1}]==0){
//                    mp[{a[i-1].first,a[i-1].second+1}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first,a[i-1].second+1}]=(mp[{a[i-1].first,a[i-1].second+1}]+dp[i-1]-mp[{a[i-1].first,a[i-1].second+1}])%MOD;
//                }
//            }
//            if(dx==-1&&dy==-1){
//                dp[i] = (dp[i-1]*2-mp[{a[i-1].first-1,a[i-1].second}]-mp[{a[i-1].first,a[i-1].second-1}])%MOD;
//                if(mp[{a[i-1].first-1,a[i-1].second}]==0){
//                    mp[{a[i-1].first-1,a[i-1].second}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first-1,a[i-1].second}]=(mp[{a[i-1].first-1,a[i-1].second}]+dp[i-1]-mp[{a[i-1].first-1,a[i-1].second}])%MOD;
//                }
//                if(mp[{a[i-1].first,a[i-1].second-1}]==0){
//                    mp[{a[i-1].first,a[i-1].second-1}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first,a[i-1].second-1}]=(mp[{a[i-1].first,a[i-1].second-1}]+dp[i-1]-mp[{a[i-1].first,a[i-1].second-1}])%MOD;
//                }
//            }
//            if(dx==1&&dy==-1){
//                dp[i] = (dp[i-1]*2-mp[{a[i-1].first+1,a[i-1].second}]-mp[{a[i-1].first,a[i-1].second-1}])%MOD;
//                if(mp[{a[i-1].first+1,a[i-1].second}]==0){
//                    mp[{a[i-1].first+1,a[i-1].second}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first+1,a[i-1].second}]=(mp[{a[i-1].first+1,a[i-1].second}]+dp[i-1]-mp[{a[i-1].first+1,a[i-1].second}])%MOD;
//                }
//                if(mp[{a[i-1].first,a[i-1].second-1}]==0){
//                    mp[{a[i-1].first,a[i-1].second-1}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first,a[i-1].second-1}]=(mp[{a[i-1].first,a[i-1].second-1}]+dp[i-1]-mp[{a[i-1].first,a[i-1].second-1}])%MOD;
//                }
//            }
//            if(dx==-1&&dy==1){
//                dp[i] = (dp[i-1]*2-mp[{a[i-1].first-1,a[i-1].second}]-mp[{a[i-1].first,a[i-1].second+1}])%MOD;
//                if(mp[{a[i-1].first-1,a[i-1].second}]==0){
//                    mp[{a[i-1].first-1,a[i-1].second}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first-1,a[i-1].second}]=(mp[{a[i-1].first-1,a[i-1].second}]+dp[i-1]-mp[{a[i-1].first-1,a[i-1].second}])%MOD;
//                }
//                if(mp[{a[i-1].first,a[i-1].second+1}]==0){
//                    mp[{a[i-1].first,a[i-1].second+1}]=dp[i-1];
//                }else{
//                    mp[{a[i-1].first,a[i-1].second+1}]=(mp[{a[i-1].first,a[i-1].second+1}]+dp[i-1]-mp[{a[i-1].first,a[i-1].second+1}])%MOD;
//                }
//            }
//        }
//
//        if(dp[i]<0){
//            cout<<"0"<<endl;
//            return;
//        }
//    }
//    for(int i=0;i<k+1;i++){
//        cout<<dp[i]<<" ";
//    }
//    cout<<dp[k]<<endl;
//}

void solve(){

}
int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1021(div2)/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}