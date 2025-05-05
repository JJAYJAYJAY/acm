#include <iostream>
#include<vector>
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
    vector<int> c(2*k+1);
    int len;
    if(n%2==1){
        len=(n/2)%k*2+1;
        for(int i=n/2-(n/2)%k+1;i<=(n/2)+(n/2)%k+1;i++){
            cout<<"? "<<i<<endl;
            int x;
            cin>>x;
            c[i-n/2+(n/2)%k]=x;
        }
    }else{
        if((n/2)%k!=0){
            len=(n/2)%k*2;
            for(int i=n/2-(n/2)%k+1;i<=(n/2)+(n/2)%k;i++){
                cout<<"? "<<i<<endl;
                int x;
                cin>>x;
                c[i-n/2+(n/2)%k]=x;
            }
        }else{
            for(int i=1;i<=k;i++){
                if(a[i]!=b[i]){
                    int l=0,r=n/k - 1;
                    int x;
                    while(l<r){
                        int mid=(l+r)/2;
                        cout<<"? "<<mid*k+i<<endl;
                        cin>>x;
                        if(x==a[i]) {
                            l = mid+1;
                        }else{
                            r = mid;
                        }
                    }
                    l--;
                    if(i==k){
                        cout<<"! "<<(l+1)*k<<" "<<n-(l+1)*k<<endl;
                        return;
                    }
                    cout<<"? "<<l*k+i+1<<endl;
                    cin>>x;
                    if(x==a[i+1]){
                        cout<<"! "<<(l+1)*k<<" "<<n-(l+1)*k<<endl;
                    }else{
                        cout<<"! "<<l*k+i<<" "<<n-l*k-i<<endl;
                    }
                    return;
                }
            }
            cout<<"! -1"<<endl;
            return;
        }

    }
    int l_flag=0;
    for(int i=1;i<=len;i++){
        int idx=i;
        if(idx>k){
            idx=idx%k;
        }
        if(c[i]!=a[idx]){
            break;
        }
        l_flag++;
    }

    int r_flag=len;
    for(int i=len;i>=1;i--){
        int idx=k+i-len;
        if(idx<1){
            idx = k+idx;
        }
        if(c[i]!=b[idx]){
            break;
        }
        r_flag--;
    }
    if(r_flag<l_flag){
        cout<<"! "<<-1<<endl;
        return;
    }else{
        cout<<"! "<<(n/2)/k*k+l_flag<<" "<<n-((n/2)/k*k+l_flag)<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1022(div2)/in/D.in", "r", stdin);
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