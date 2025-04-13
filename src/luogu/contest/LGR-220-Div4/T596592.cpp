#include <iostream>
#include<queue>
using namespace std;
const int N = 1e3+10;
int n,s,m;

queue<long long> q[N];

vector<int> ops;
void solve() {
    scanf("%d%d%d",&n,&s,&m);
    for(int i=0;i<m;i++){
        int op;
        scanf("%d",&op);
        ops.push_back(op);
    }
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        while(t--){
            long long x;
            scanf("%lld",&x);
            q[i].push(x);
        }
    }
    long long ans=0;
    if(!q[s].empty()) {
        ans += q[s].front();
        q[s].pop();
    }
    for(int i=0;i<m;i++){
        int op = ops[i];
        if(op==1){
            if(s+1>n){
                s = 1;
            }else{
                s++;
            }
            if(!q[s].empty()) {
                ans += q[s].front();
                q[s].pop();
            }
        }else{
            if(s-1<1){
                s = n;
            }else{
                s--;
            }
            if(!q[s].empty()) {
                ans += q[s].front();
                q[s].pop();
            }
        }
    }
    printf("%lld\n",ans);
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-220-Div4/in/T596592.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}