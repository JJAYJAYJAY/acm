#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

int n,m;
struct node{
    long long val;
    int id;

    bool operator < (const node &other) const {
        return val < other.val;
    }
};

vector<node> a;

struct Query{
    int l,r;
    long long id;
    bool operator < (const Query &other) const {
        return r < other.r;
    }
};
vector<Query> q;

int lowbit(int x) {
    return x & -x;
}

int tr[1000005]; //存入左端点在i左侧得值

void add(int l){
    for(;l<=n;l+=lowbit(l)){
        tr[l]++;
    }
}
int query(int x){
    int ans = 0;
    for(;x;x-=lowbit(x)){
        ans += tr[x];
    }
    return ans;
}

struct Pair{
    int l,r;
    bool operator < (const Pair &other) const {
        return r < other.r;
    }
};
vector<Pair> pairs;
void add_pair(node x,node y){
    if(x.id>y.id){
        pairs.push_back({y.id,x.id});
    }else{
        pairs.push_back({x.id,y.id});
    }
}

void solve() {
    scanf("%d%d", &n, &m);
    if(n == 1){
        printf("0\n");
        return;
    }
    a.push_back({0,0});//哨兵
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back({x,i});
    }
    sort(a.begin(),a.end());
    add_pair(a[1],a[2]);
    for(int i=2;i<n;i++){
        if(abs(a[i].val - a[i-1].val) == abs(a[i+1].val - a[i].val)){
            add_pair(a[i],a[i+1]);
            add_pair(a[i],a[i-1]);
        }else if(abs(a[i].val - a[i-1].val) < abs(a[i+1].val - a[i].val)){
            add_pair(a[i],a[i-1]);
        }else{
            add_pair(a[i],a[i+1]);
        }
    }
    add_pair(a[n-1],a[n]);
    sort(pairs.begin(),pairs.end());
    for(long long i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q.push_back({l,r,i});
    }
    sort(q.begin(),q.end());
    long long ans = 0;
    int idx = 0;
    for(int i=0;i<m;i++){
        while(idx<pairs.size()&&pairs[idx].r <= q[i].r){
            add(pairs[idx].l);
            idx++;
        }
        ans += (long long)(query(q[i].r) - query(q[i].l-1))*q[i].id;
    }
    printf("%lld\n",ans);
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P5000-P6000/in/P5677.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}