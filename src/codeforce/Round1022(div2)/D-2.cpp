#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    if(n==2&&k==1){
        cout<<"! 1 1"<<endl;
        return;
    }
    if(k==1){
        cout<<"! -1"<<endl;
        return;
    }
    if(2*k==n){
        cout<<"! "<<k<<" "<<k<<endl;
        return;
    }
    vector<int> a(k+1);
    vector<int> b(k+1);
    for(int i=1;i<=k;i++){
        cout<<"? "<<i<<endl;
        int x;
        cin>>x;
        a[i]=x;
    }
    for(int i=n-k+1;i<=n;i++) {
        cout << "? " << i << endl;
        int x;
        cin >> x;
        b[i - n + k] = x;
    }
    vector<int> c(k+1);
    for(int i=1;i<=k;i++){
        int idx=n%k+i;
        if(idx>k){
            idx-=k;
        }
        c[i]=b[idx];
    }
    for(int i=1;i<=k;i++){
        if(a[i]!=c[i]){
            int l=0,r=((n+(n%k))/k)-1;
            while(l<r){
                int mid=(l+r)/2;
                cout<<"? "<<mid*k+i<<endl;
                int x;
                cin>>x;
                if(x==a[i]) {
                    l = mid+1;
                }else{
                    r=mid;
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1022(div2)/in/D-2.in", "r", stdin);
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