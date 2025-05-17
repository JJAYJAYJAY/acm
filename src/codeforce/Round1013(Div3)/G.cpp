#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int s,k;
    cin>>s>>k;
    int rest=s%k;
    if(rest==0){
        cout<<k<<endl;
        return;
    }else{
        if (s > k * k) {
            cout << max(1, k - 2) << endl;
            return;
        }
        vector<bool> st(s+1,false);
        for(int i=0;i<=s;i+=k){
            st[i]=true;
        }
        bool flag= false;
        for(int i=k-1;i>=1;i--){
            vector<bool> now_st(s+1,false);
            if(flag){
                for(int j=i;j<=s;j++){
                    now_st[j]=st[j-i] | now_st[j-i];
                }
            }else{
                for(int j=s-i;j>=0;j--){
                    now_st[j]=st[j+i] | now_st[j+i];
                }
            }
            st = now_st;
            if(st[s]){
                cout<<i<<endl;
                return;
            }
            flag = !flag;
        }
        cout<<1<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1013(Div3)/in/G.in", "r", stdin);
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