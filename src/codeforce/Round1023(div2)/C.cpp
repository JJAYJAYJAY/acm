#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
const ll N =-1e18;
void solve() {
    ll n,k;
    string s;
    cin>>n>>k>>s;
    s=" "+s;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll all_mx = LLONG_MIN;
    vector<ll> p(n+1,0);
    vector<ll> ps(n+2,0);
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            p[i]=0;
        }else{
            p[i] = max(p[i-1]+a[i],a[i]);
            all_mx = max(all_mx,p[i]);
        }
    }

    if(all_mx>k){
        cout<<"No"<<endl;
        return;
    }
    if(all_mx==k){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                cout<<N<<" ";
            }else{
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    vector<int> idxs;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            idxs.push_back(i);
        }
    }
    if(idxs.empty()){
        cout<<"No"<<endl;
        return;
    }

    for(ll i=n;i>=1;i--){
        if(s[i]=='1'){
            ps[i] = max(ps[i+1]+a[i],a[i]);
        }else{
            ps[i] = 0;
        }
    }
    for(int i=0;i<idxs.size();i++){
        cout<<"Yes"<<endl;
        int l = idxs[i];
        int r = idxs[i];
        while(r+1<=n&&s[r+1]=='0'){
            i++;
            r++;
        }
        ll now = max(0ll,p[l-1])+max(0ll,ps[r+1]);
        bool flag= false;
        for(int j=1;j<=n;j++){
            if(s[j]=='1'){
               cout<<a[j]<<" ";
            }else{
                if(j>=l&&j<=r){
                    if(!flag){
                        cout<<k-now<<" ";
                        flag=true;
                    }else{
                        cout<<0<<" ";
                    }
                }else{
                    cout<<N<<" ";
                }
            }
        }
        cout<<endl;
        return;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1023(div2)/in/C.in", "r", stdin);
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