#include <iostream>
#include <algorithm>

#define int __int128
using namespace std;
const int N = 2e5+5, MOD = 998244353;
struct Segtree{
    int l, r;
    int sum, add;
    int x; // 储存分子的值
    int len2; // 所有子树的len^2乘sum^2
    int len; // 所有子树的len,包括自己乘sum
} tr[N << 2];
long long w[N];

int gcd(int x, int y){
    if (y) while((x %= y) && (y %= x));
    return x + y;
}
int power(int a, int x){
    int ans = 1;
    for (; x; x >>= 1){
        if (x & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}

std::string int128_to_string(__int128 num) {
    if (num == 0) return "0";

    bool is_negative = false;
    if (num < 0) {
        is_negative = true;
        num = -num;
    }

    std::string result;
    while (num > 0) {
        result += static_cast<char>('0' + (num % 10));
        num /= 10;
    }

    if (is_negative) {
        result += '-';
    }

    std::reverse(result.begin(), result.end());
    return result;
}


void push_up(int u){
    Segtree& root = tr[u],&l = tr[u << 1], & r = tr[u << 1 | 1];
//    cout<<int128_to_string(u)<<":"<<int128_to_string(root.l)<<" "<<int128_to_string(root.r)<<":"<<int128_to_string(root.sum)<<endl;
    root.sum = (l.sum + r.sum);
//    cout<<int128_to_string(u)<<":"<<int128_to_string(root.l)<<" "<<int128_to_string(root.r)<<":"<<int128_to_string(root.sum)<<endl;
    root.len2 = l.len2 + r.len2 + (root.r - root.l + 1) * (root.r - root.l + 1);
    root.len = l.len + r.len + (root.r - root.l + 1) * root.sum;
    root.x = l.x + r.x + root.sum * root.sum;
}


void build(int u,int l,int r){
    if(l==r) tr[u] = {l, r, w[l], 0,w[l]*w[l],1,w[l]};
    else {
        tr[u] = {l, r, 0, 0, 0,0,0};
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void push_down(int u){
    Segtree& root = tr[u],& l = tr[u << 1], & r = tr[u << 1 | 1];
    if(root.add){
        l.add += root.add;
        l.x += root.add*root.add*l.len2+2 * root.add*l.len;
        l.sum += (l.r - l.l + 1) * root.add;
        l.len+=l.len2*root.add;
        r.add += root.add;
        r.x += root.add*root.add*r.len2+2 * root.add*r.len;
        r.sum += (r.r - r.l + 1) * root.add;
        r.len+=r.len2*root.add;
        root.add = 0;
    }
}

void modify(int u,int l,int r,int x){
    Segtree& root = tr[u];

    if(root.l >= l && root.r <= r){
        root.add += x;
        root.x += 2 * root.len * x  + x*x*root.len2;
//        cout<<int128_to_string(root.sum)<<" "<<int128_to_string(root.l)<<" "<<int128_to_string(root.r)<<endl;
        root.sum += (root.r - root.l + 1) * x;
        root.len += root.len2 * x;
//        cout<<int128_to_string(root.sum)<<" "<<int128_to_string(root.l)<<" "<<int128_to_string(root.r)<<endl;
        return;
    }
    push_down(u);
    int mid = (root.l + root.r) >> 1;
    if(l <= mid) modify(u << 1, l, r, x);
    if(r > mid) modify(u << 1 | 1, l, r, x);
    push_up(u);
}

void query(){
    int x = tr[1].x;
    int y = tr[1].sum;
//    cout<< int128_to_string(x) << " " << int128_to_string(y) << endl;
    int gd = gcd(x, y);
    x /= gd;
    y /= gd;
//    cout<< int128_to_string(x) << " " << int128_to_string(y) << endl;
    int ans = ((x%MOD) * power(y, MOD - 2)) % MOD; // 计算分数的逆元
    cout<< int128_to_string(ans) << endl;
}

long long n,m;
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1, 1, n);

    for(int i=1;i<=m;i++){
        long long op;
        cin>>op;
        if(op==1){
            long long l,r,v;
            cin>>l>>r>>v;
            modify(1, l, r, v);
        }else{
            query();
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("src/luogu/P4000-P5000/in/P4927.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}