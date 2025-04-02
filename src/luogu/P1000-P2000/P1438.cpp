//
// Created by lyh on 2025/4/2.
//
#include <iostream>

using namespace std;
const int N=1e5+10;
struct Segtree{
    int l,r;
    long long sum,add;
}tr[N<<2];
int w[N];

void push_up(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void push_down(int u){
    Segtree &root = tr[u],&left = tr[u<<1],&right = tr[u<<1|1];
    if(root.add!=0){
        left.add += root.add;
        right.add += root.add;
        left.sum += (left.r - left.l+1)*root.add;
        right.sum += (right.r - right.l+1)*root.add;
        root.add = 0;
    }
}

void build(int u,int l,int r){
    if(l==r){
        tr[u] = {l,r,w[l],0};
    }else{
        tr[u] = {l,r,0,0};
        int mid = (l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        push_up(u);
    }
}

void modify(int u,int l,int r,long long k){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].sum += (tr[u].r - tr[u].l+1)*k;
        tr[u].add += k;
    }else{
        push_down(u);
        int mid = (tr[u].l+tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        push_up(u);
    }
}

long long query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u].sum;
    }else{
        push_down(u);
        int mid = (tr[u].l+tr[u].r)>>1;
        long long ans = 0;
        if(l<=mid) ans+=query(u<<1,l,r);
        if(r>mid) ans+=query(u<<1|1,l,r);
        return ans;
    }
}

int n,m;
int a[N];
int main(){
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1438.in","r",stdin);
#endif
scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        w[i] = a[i]-a[i-1];
    }
    build(1,1,n);
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int l,r,k,d;
            scanf("%d%d%d%d",&l,&r,&k,&d);
            modify(1,l,l,k);
            if(l+1<=r)
                modify(1,l+1,r,d);
            if(r+1<=n)
                modify(1,r+1,r+1,-(k+(r-l)*d));
        }else{
            int x;
            scanf("%d",&x);
            printf("%lld\n",query(1,1,x));
        }
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}