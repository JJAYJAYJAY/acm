#include <iostream>

using namespace std;

const int N = 5e5 + 5;
long long tr1[N];
int n,m;

int lowbit(int x) {
    return x & -x;
}

void add(long long tr[],int x,long long c){
    for(;x<=n;x+=lowbit(x)){
        tr[x] += c;
    }
}

long long sum(long long tr[],int x){
    long long ans = 0;
    for(;x;x-=lowbit(x)){
        ans += tr[x];
    }
    return ans;
}

long long query(int l,int r){
    return sum(tr1,r) - sum(tr1,l-1);
}

void solve() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        add(tr1,i,x);
    }
    while(m--){
        int op;
        scanf("%d",&op);
        if(op == 1){
            int x,c;
            scanf("%d%d",&x,&c);
            add(tr1,x,c);
        } else {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(x,y));
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P3000-P4000/in/P3374.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}