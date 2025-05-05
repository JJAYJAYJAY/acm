#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    long long sum=0ll;
    long long mn = 1e9+10;
    long long mx = -1;
    int cnt =0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        a[i]=x;
        sum+=x;
        mx = max(mx,x);
        mn = min(mn,x);
    }
    for(int i=0;i<n;i++){
        if(a[i]==mx){
            cnt++;
        }
    }
    if(abs(mx-mn)>k+1||(mx-mn==k+1&&cnt>1)){
        cout<<"Jerry"<<endl;
        return;
    }else{
        if(sum%2==1){
            cout<<"Tom"<<endl;
            return;
        }else{
            cout<<"Jerry"<<endl;
            return;
        }
    }

}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1023(div2)/in/B.in", "r", stdin);
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