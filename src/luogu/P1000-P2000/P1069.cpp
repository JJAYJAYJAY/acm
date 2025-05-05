#include <iostream>
#include<vector>
using namespace std;
const int MAX = 30000;
vector<bool> st(MAX + 1, false);
vector<int> ps;
using ll = long long;
void solve() {
    int n;
    cin>>n;
    int m1,m2;
    cin>>m1>>m2;
    int i=0;
    vector<int> np(20000,0);
    if(m1==1){
        cout<<0<<endl;
        return;
    }
    while(m1!=1){
        if(m1%ps[i]==0) {
            while(m1%ps[i]==0){
                m1/=ps[i];
                np[i]+=m2;
            }
        }
        i++;
    }
    int ans = 1e9;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int j=0;
        vector<int> x_p(ps.size());
        while(j<ps.size()){
            if(x%ps[j]==0){
                while(x%ps[j]==0){
                    x/=ps[j];
                    x_p[j]++;
                }
            }
            j++;
        }
        bool flag = true;
        int mx=-1e9;
        for(int j=0;j<ps.size()&&flag;j++){
            if(np[j]!=0&&x_p[j]==0) flag = false;
            if(np[j]!=0&&x_p[j]!=0) {
                if(np[j]%x_p[j]==0){
                    mx = max(mx, np[j]/x_p[j]);
                }else{
                    mx = max(mx, np[j]/x_p[j]+1);
                }
            }
        }
        if(flag){
            ans = min(ans, mx);
        }
    }
    if(ans==1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1069.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
//    cin>>work;
    for(int i = 2; i <= MAX; i++){
        if(!st[i]){
            ps.push_back(i);
            if ((ll)i * i <= MAX) {
                for(int j = i*i; j <= MAX; j += i)
                    st[j] = true;
            }
        }
    }

    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}