//
// Created by lyh on 2025/4/2.
//
#include <iostream>
#include <cmath>

using namespace std;
const int N =1e6+10;
const long long INF = -1e18;
struct Segtree{
    int l,r;
    long long max,add;
    bool change_flag= false;
}tr[N<<2];
long long w[N];



//修改值的话，直接重新计算sum，并重置add，push_down时进行赋值而不是累加

void push_up(int u){
    tr[u].max = max(tr[u<<1].max, tr[u<<1|1].max);
}
void build(int u,int l,int r){
    if(l==r){
        tr[u] = {l,r,w[l],0};
    }else{
        tr[u] = {l,r,INF,0};
        int mid = (l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        push_up(u);
    }
}
void push_down(int u){
    Segtree &root = tr[u], &left=tr[u<<1],&right=tr[u<<1|1];
    if(root.change_flag){
        left.change_flag = right.change_flag = true;
        left.max = root.add;
        right.max = root.add;
        left.add = right.add = root.add;
        root.change_flag = false;
        root.add = 0;
    }else{
        if(root.add){
            left.add += root.add;
            right.add += root.add;
            left.max += root.add;
            right.max += root.add;
            root.add = 0;
        }
    }
}

void modify(int u,int l,int r,long long k,int change_model){
    if(tr[u].l>=l&&tr[u].r<=r) {
        if(change_model == 1){
            tr[u].max = k;
            tr[u].add = k;
            tr[u].change_flag = true;
        }else{
            tr[u].max += k;
            tr[u].add += k;
        }
    }else{
        push_down(u);
        int mid = (tr[u].l+tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r,k,change_model);
        if(r>mid) modify(u<<1|1,l,r,k,change_model);
        push_up(u);
    }
}

long long query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) {
        return tr[u].max;
    }else{
        push_down(u);
        int mid = (tr[u].l+tr[u].r)>>1;
        long long ans = INF;
        if(l<=mid) ans = max(ans,query(u<<1,l,r));
        if(r>mid) ans = max(ans,query(u<<1|1,l,r));
        return ans;
    }
}

int n,q;
int main(){
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1253-3.in","r",stdin);
#endif
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    build(1,1,n);
    while(q--){
        int op,l,r;
        long long k;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%lld",&k);
            modify(1,l,r,k,1);
        }else if(op==2){
            scanf("%lld",&k);
            modify(1,l,r,k,2);
        }else{
            cout<<query(1,l,r)<<endl;
        }
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}
