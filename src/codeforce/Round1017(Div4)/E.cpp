#include <iostream>
#include<vector>
using namespace std;
int t;

void solve() {
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<long long> cnt(31);
        for(int i=0;i<30;i++){
            cnt[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int b=30;b>=0;b--){
                if(a[i]>>b & 1){
                    cnt[b]++;
                }
            }
        }
        long long maxx = 0;
        for(int i=0;i<n;i++){
            long long ans = 0;
            for(int b=30;b>=0;b--){
                if(a[i]>>b & 1){
                    ans += (1ll<<b)*(n-cnt[b]);
                } else {
                    ans += (1ll<<b)*cnt[b];
                }
            }
            maxx = max(maxx,ans);
        }
        cout<< maxx << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/E.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}