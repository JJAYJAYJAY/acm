#include <iostream>

using namespace std;

const int N = 5e5 + 5;
long long tr1[N], tr2[N];
int n,m;
int a[N];

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

long long query(int x){
    return sum(tr1,x) * (x + 1) - sum(tr2,x);
}

void solve() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[i] = x;
    }
    for(int i=1;i<=n;i++){
        long long b = a[i] - a[i - 1];
        add(tr1,i,b);
        add(tr2,i,b * i);
    }
    while(m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            add(tr1, x, c);
            add(tr1, y + 1, -c);
            add(tr2, x, c * x);
            add(tr2, y + 1, -c * (y + 1));
        } else {
            int x;
            scanf("%d", &x);
            printf("%lld\n", query(x)-query(x-1));
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P3000-P4000/in/P3368.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}