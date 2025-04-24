#include <iostream>
#include "vector"
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a;
    int mn_a=1e9;
    int mx_a=-1e9;
    vector<int> b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mn_a=min(mn_a,x);
        mx_a=max(mx_a,x);
        a.push_back(x);
    }
    int sum=-1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    int cnt=0;
    int mx=-1e9;
    for(int i=0;i<n;i++){
        if(b[i]!=-1){
            if(sum==-1){
                sum = b[i]+a[i];
            }else{
                if(sum!=b[i]+a[i]){
                    cout<<0<<endl;
                    return;
                }
            }
        }else{
            mx=max(mx,k-a[i]);
            if(mx>k){
                cout<<0<<endl;
                return;
            }
            cnt++;
        }
    }
    if(sum!=-1){
        if(sum-mx_a<0||mn_a+k<sum){
            cout<<0<<endl;
            return;
        }
        cout<<1<<endl;
        return;
    }else{
        if(k+mn_a<mx_a){
            cout<<0<<endl;
            return;
        }else{
            cout<<k+mn_a-mx_a+1<<endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1020(div3)/in/C.in", "r", stdin);
#endif
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}