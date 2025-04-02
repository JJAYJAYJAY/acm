//
// Created by lyh on 2025/4/2.
//
#include <iostream>
using namespace std;
const int N = 5e5+10;
const long long INF = -1e18;

//单点修改+连续区间最大和
struct Segtree{
    int l,r;
    long long max,max_l,max_r,sum;
}tr[N<<2];

long long w[N];

void push_up(int u){
//    cout<<"更新"<<u<<endl;
    Segtree &root = tr[u],&left = tr[u<<1],&right = tr[u<<1|1];
    root.sum = left.sum + right.sum;
    root.max = max(max(left.max,right.max),left.max_r+right.max_l);
    root.max_l = max(left.max_l,left.sum+right.max_l);
    root.max_r = max(right.max_r,right.sum+left.max_r);
}

void build(int u,int l,int r){
    if(l==r) tr[u]={l,r,w[l],w[l],w[l],w[l]};
    else{
        tr[u] = {l,r,INF,INF,INF};
        int mid = (l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        push_up(u);
    }
}

void modify(int u,int l,int r,long long x){
    if(tr[u].l>=l&&tr[u].r<=r) {
        tr[u].sum = tr[u].max = tr[u].max_l = tr[u].max_r = x;
    }else{
        int mid = (tr[u].l+tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r,x);
        if(r>mid) modify(u<<1|1,l,r,x);
        push_up(u);
    }
}

Segtree query(int u,int l,int r){
    //查询时也要做区间合并
    Segtree ans = {0,0,INF,INF,INF,0};
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u];
    }else{
        int mid = (tr[u].l+tr[u].r)>>1;
        Segtree left,right;
        if(l<=mid){
            left = query(u<<1,l,r);
            ans.sum+= left.sum;
            ans.max = max(ans.max,left.max);
            ans.max_l = left.max_l;
            ans.max_r = left.max_r;
        }
        if(r>mid) {
            right = query(u<<1|1,l,r);
            ans.sum+= right.sum;
            ans.max = max(ans.max,right.max);
            ans.max_l = right.max_l;
            ans.max_r = right.max_r;
        }
        if(l<=mid && r>mid){
            ans.max = max(ans.max,left.max_r+right.max_l);
            ans.max_l = max(left.max_l,left.sum+right.max_l);
            ans.max_r = max(right.max_r,right.sum+left.max_r);
        }

        return ans;
    }
}

int n,m;

int main(){
#ifdef LOCAL
    freopen("src/luogu/P4000-P5000/in/P4513.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }

    build(1,1,n);
//    cout<<tr[1].l<<" "<<tr[1].r<<endl;
    while(m--){
        int op,l,r;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&l,&r);
            if(l>r) swap(l,r);
            printf("%lld\n",query(1,l,r).max);
        }else{
            long long x,y;
            scanf("%lld%lld",&x,&y);
            modify(1,x,x,y);
        }
    }
//    cout<<tr[1].max<<endl;
#ifdef LOCAL
    fclose(stdin);
#endif
}