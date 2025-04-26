#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> a;
    int n,k;
    cin>>n>>k;
    int cnt =0;
    a.push_back(0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<=k){
            a.push_back(1);
            cnt++;
        }else{
            a.push_back(-1);
        }
    }
    if(cnt < 2){
        cout<<"NO"<<endl;
        return;
    }
    for(int z=0;z<2;z++){
        if(z) reverse(a.begin()+1,a.end());
        vector<int> b;
        b.push_back(0);
        for(int i=1;i<=n;i++){
            b.push_back(a[i]+b[i-1]);
        }
        int p=1;
        for(int i=1;i<n;i++){
            if(b[p]>=0){
                if((p<i&&b[i]-b[p]>=0)||(p<i && b[n]-b[i]>=0)){
                    cout<<"YES"<<endl;
                    return;
                }
            }
            if(b[i]>=0){
                if(b[i]<(b[p]<0?1e9:b[p])) p=i;
            }
        }

    }
    cout<<"NO"<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1019(div2)/in/C.in", "r", stdin);
#endif
    //快速输入
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}