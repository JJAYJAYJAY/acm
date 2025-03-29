//
// Created by lyh on 2025/3/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N =1e4+10;
int  n,q;
vector<vector<int>> v;
struct query{
    int op,id;
    vector<int> l,r;
}qu[N];

vector<int> read(){
    string s;
    cin>>s;
    vector<int> res;
    for(int i=0;i<s.length();i+=5){
        int x = 0;
        for(int j=0;j<4;j++){
            x = x*16 + (s[i+j]>='a'?s[i+j]-'a'+10:s[i+j]-'0');
        }
        res.push_back(x);
    }
    v.emplace_back(res);
    return res;
}

struct SegmentTree{
    struct node{
        int l,r;
        int cnt = 0;//多少地址被分配了
        int st=-0x3f3f3f3f; // 懒标记
        int mx=-0x3f3f3f3f,mn=0x3f3f3f3f;
    } tr[N<<2];

    void build(int l,int r,int u=1){
        tr[u].l = l,tr[u].r = r;
        if(l==r){
            return;
        }
        int mid = l+r>>1;
        build(l,mid,u<<1);
        build(mid+1,r,u<<1|1);
        pushup(u);
    }

    void pushup(int u){
        tr[u].cnt = tr[u<<1].cnt + tr[u<<1|1].cnt;
        tr[u].mx = max(tr[u<<1].mx,tr[u<<1|1].mx);
        tr[u].mn = min(tr[u<<1].mn,tr[u<<1|1].mn);
    }

    void pushdown(int u){
        if(tr[u].st!=-0x3f3f3f3f){
            tr[u<<1].st = tr[u<<1|1].st = tr[u].st;
            tr[u<<1].cnt = tr[u<<1].r - tr[u<<1].l + 1;
            tr[u<<1|1].cnt = tr[u<<1|1].r - tr[u<<1|1].l + 1;
            tr[u<<1].mx = tr[u<<1].mn = tr[u].st;
            tr[u<<1|1].mx = tr[u<<1|1].mn = tr[u].st;
            tr[u].st = -0x3f3f3f3f;
        }
    }

    //不保证修改的合法性，必须验证合法性再调用这个函数
    void modify(int l,int r,int id,int u=1){
        if(tr[u].l>=l&&tr[u].r<=r){
            tr[u].cnt = tr[u].r - tr[u].l + 1;
            tr[u].st = id;
            tr[u].mx = tr[u].mn = id;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(l,r,id,u<<1);
        if(r>mid) modify(l,r,id,u<<1|1);
        pushup(u);
    }

    int querryMax(int l,int r,int u=1){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u].mx;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = -0x3f3f3f3f;
        if(l<=mid) res = max(res,querryMax(l,r,u<<1));
        if(r>mid) res = max(res,querryMax(l,r,u<<1|1));
        return res;
    }
    int querryMin(int l,int r,int u=1){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u].mn;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0x3f3f3f3f;
        if(l<=mid) res = min(res,querryMin(l,r,u<<1));
        if(r>mid) res = min(res,querryMin(l,r,u<<1|1));
        return res;
    }

    int querry(int l,int r,int u=1){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u].cnt;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if(l<=mid) res += querry(l,r,u<<1);
        if(r>mid) res += querry(l,r,u<<1|1);
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    v.emplace_back(vector<int>(n/16,-1));
    for(int i=1;i<=q;i++){
        cin>>qu[i].op;
        if(qu[i].op==1){
            cin>>qu[i].id;
            qu[i].l = read();
            qu[i].r = read();
            if(qu[i].r != vector<int>(n/16,65535)){
                vector<int> tmp = qu[i].r;
                int t = tmp.size()-1;
                while(tmp[t]==65535){
                    tmp[t--]=0;
                }
                tmp[t]++;
                v.emplace_back(tmp);
            }
        }
        else if(qu[i].op==2){
            qu[i].l =qu[i].r = read();
        }
        else{
            qu[i].l = read();
            qu[i].r = read();
        }
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    SegmentTree tr;
    tr.build(1,v.size()-1);
    for(int i=1;i<=q;i++){
        int l = lower_bound(v.begin(),v.end(),qu[i].l) - v.begin();
        int r = lower_bound(v.begin(),v.end(),qu[i].r) - v.begin();
        int cnt = tr.querry(l,r),mx=tr.querryMax(l,r),mn=tr.querryMin(l,r);
        if(qu[i].op==1){
            if(cnt==0 ||(mx==mn&&mx==qu[i].id&&cnt<r-l+1)){
                tr.modify(l,r,qu[i].id);
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(qu[i].op==2){
            cout<<(cnt?mx:0)<<endl;
        }
        else{
            cout<<(cnt == r - l + 1&&mx==mn?mx:0)<<endl;
        }
    }
    return 0;
}