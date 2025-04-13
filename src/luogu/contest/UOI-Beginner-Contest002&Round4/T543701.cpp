#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 5;

struct Node {
    long long l, r;
    long long max_val, sum, cost, max_idx;
} tr[N << 2];

void pushup(int u) {
    Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    root.max_val = max(left.max_val, right.max_val);
    root.max_idx = left.max_val > right.max_val ? left.max_idx : right.max_idx;
    root.sum = left.sum + right.sum;
    root.cost = left.cost+right.cost+(root.max_val - left.max_val)*(left.r - left.l + 1)+(root.max_val - right.max_val)*(right.r -right.l + 1);
    if(left.max_val > right.max_val){
        root.cost = min(root.cost,left.cost + right.cost + (right.r - left.r + 1)*(right.r - left.r + 1));
    }else{
        root.cost = min(root.cost,left.cost + right.cost + (right.l - left.l  + 1)*(right.l - left.l  + 1));
    }
}

void build(int u, long long l,long long r, const vector<long long>& a) {
    tr[u].l = l;
    tr[u].r = r;
    if (l == r) {
        tr[u].max_val = a[l];
        tr[u].sum = a[l];
        tr[u].cost = 0;
        tr[u].max_idx = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid, a);
    build(u << 1 | 1, mid + 1, r, a);
    pushup(u);
}

void update(int u,long long pos, long long val) {
    if (tr[u].l == tr[u].r) {
        tr[u].max_val = val;
        tr[u].sum = val;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (pos <= mid) {
        update(u << 1, pos, val);
    } else {
        update(u << 1 | 1, pos, val);
    }
    pushup(u);
}

Node query(int u, long long l, long long r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u];
    }
    long long mid = (tr[u].l + tr[u].r) >> 1;
    if (r <= mid) {
        return query(u << 1, l, r);
    } else if (l > mid) {
        return query(u << 1 | 1, l, r);
    } else {
        Node left = query(u << 1, l, mid);
        Node right = query(u << 1 | 1, mid + 1, r);
        long long max_val = max(left.max_val, right.max_val);
        long long cost = left.cost + right.cost + (max_val - left.max_val) * (left.r - left.l + 1) + (max_val - right.max_val) * (right.r - right.l + 1);
        long long max_idx = left.max_val > right.max_val ? left.max_idx : right.max_idx;
        if(left.max_val > right.max_val) {
            cost = min(cost, left.cost + right.cost + (right.r - left.r + 1) * (right.r - left.r + 1));
        } else {
            cost = min(cost, left.cost + right.cost + (right.l - left.l + 1) * (right.l - left.l + 1));
        }
        return {0, 0, max_val, left.sum + right.sum, cost, max_idx};
    }
}


void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n+1);
    for (int i = 1; i <=n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n, a);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long k, x;
            cin >> k >> x;
            update(1, k, x);
        } else {
            long long l, r;
            cin >> l >> r;
            cout<<query(1, l, r).cost<<endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/UOI-Beginner-Contest002&Round4/in/T543701.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}