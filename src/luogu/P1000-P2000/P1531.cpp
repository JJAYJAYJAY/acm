//
// Created by lyh on 2025/4/1.
//
#include <iostream>

using namespace std;
const int N = 2e5+10;
struct SegTree{
    int l,r;
    int max=-0x3f3f3f3f;
}tr[N<<2];
int w[N];

int n,m;

void pushup(int u){
    tr[u].max = max(tr[u<<1].max,tr[u<<1|1].max);
}

void build(int u,int l,int r){
    if(l==r){
        tr[u].l=l,tr[u].r=r;
        tr[u].max=w[l];
    }
    else{
        tr[u].l=l,tr[u].r=r;
        int mid=(l+r)>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

//这道题是单点修改，不需要pushdown，为了熟悉数据结构还是考虑写区间修改
void modify(int u,int l,int r,int v){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].max=max(tr[u].max,v);
        return;
    }else{
        int mid = (tr[u].l+tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r,v);
        if(r>mid) modify(u<<1|1,l,r,v);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(l<=tr[u].l&&r>=tr[u].r){
        return tr[u].max;
    }else{
        int mid = (tr[u].l+tr[u].r)>>1;
        int res = 0;
        if(l<=mid) res = max(res,query(u<<1,l,r));
        if(r>mid) res = max(res,query(u<<1|1,l,r));
        return res;
    }
}

int main(){
    #ifdef LOCAL
        freopen("src/luogu/P1000-P2000/in/P1531.in","r",stdin);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    build(1,1,n);
    while(m--){
        char op[2];
        int x,y;
        scanf("%s%d%d",op,&x,&y);
        if(op[0]=='Q'){
            cout<<query(1,x,y)<<endl;
        }else{
            modify(1,x,x,y);
        }
    }
    #ifdef LOCAL
    fclose(stdin);
    #endif
    return 0;
}