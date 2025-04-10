#include <iostream>
#include "map"
using namespace std;
const int N =6e6+10;
int son[N][2],idx,a[N],id[N];

void insert(int x, int idd){
    int p=0;
    for(int i=30;i>=0;i--){
        id[p] = max(idd,id[p]);
        int u = x>>i &1;
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    id[p] = max(idd,id[p]);
//    cout<<"X:idx"<<x<<" "<<idx<<endl;
}
int t;
int n,k;

int find_max(int x){
    int p=0,maxx=-0x3f3f3f3f;
    for(int i=30;i>=0;i--){
        int u = x>>i &1;
        int ki = k>>i &1;
        if(ki==1){
            if(son[p][u^1]){
                p=son[p][u^1];
            } else {
                return maxx;
            }
        } else {
            if(son[p][u^1]){
                maxx = max(maxx,id[son[p][u^1]]);
            }
            if(son[p][u]){
                p=son[p][u];
            } else {
                return maxx;
            }
        }
    }
    maxx = max(maxx,id[p]);
    return maxx;
}

void solve() {
    scanf("%d", &t);
    while(t--){
        for(int i=0;i<=idx;i++){
            son[i][0]=son[i][1]=0;
            id[i]=0;
        }
        idx=0;
        scanf("%d%d", &n, &k);

        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        if(k==0){
            cout<<1<<endl;
            continue;
        }
        int minn = 0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            int res = find_max(a[i]);
            insert(a[i],i);
            minn = min(minn, i - res+1);
        }
        if(minn == 0x3f3f3f3f) cout<<-1<<endl;
        else cout<<minn<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1016(Div3)/in/G.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}