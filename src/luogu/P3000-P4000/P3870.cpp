//
// Created by lyh on 2025/4/2.
//
#include <iostream>

using namespace std;
const int N = 1e5+10;

struct SegTree {
    int l, r;
    int sum,change;
}tr[N<<2];

void push_up(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u,int l,int r){
    if(l==r){
        tr[u] = {l,r,0,0};
    }else{
        tr[u] = {l,r,0,0};
        int mid = (l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        push_up(u);
    }
}

void push_down(int u){
    SegTree &root = tr[u],&left = tr[u<<1],&right = tr[u<<1|1];
    if(root.change){
        left.change ^=1;
        right.change ^=1;
        left.sum = (left.r - left.l+1) - left.sum;
        right.sum = (right.r - right.l+1) - right.sum;
        root.change = 0;
    }
}

void modify(int u,int l,int r){
//    cout<<tr[u].l<<" "<<tr[u].r<<endl;
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].sum = (tr[u].r - tr[u].l+1) - tr[u].sum;
        tr[u].change = tr[u].change^1;
    }else{
        push_down(u);
        int mid = (tr[u].l+tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r);
        if(r>mid) modify(u<<1|1,l,r);
        push_up(u);
    }
}

int query(int u,int l ,int r){
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u].sum;
    }else{
        push_down(u);
        int mid = (tr[u].l+tr[u].r)>>1;
        int res = 0;
        if(l<=mid) res+=query(u<<1,l,r);
        if(r>mid) res+=query(u<<1|1,l,r);
        return res;
    }
}

int n,m;
int main(){
#ifdef LOCAL
        freopen("src/luogu/P3000-P4000/in/P3870.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    build(1,1,n);
    while(m--){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==0){
            modify(1,l,r);
        }else{
            cout<<query(1,l,r)<<endl;
        }
    }
#ifdef LOCAL
    fclose(stdin);
#endif
    return 0;
}