//
// Created by lyh on 2025/3/27.
//
#include<iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int N =1e5+10;
int n,m;

struct DualComparator {
    bool operator()(const std::pair<long long, int>& a,
                    const std::pair<long long, int>& b) const {
        if (a.first != b.first) {
            return a.first > b.first;  // 第一个元素从大到小
        }
        return a.second < b.second;    // 第二个元素从小到大
    }
};

map<pair<int,int>,long long> edges;
multimap<long long, int, greater<long long>>e[N];

void orderedInsert(multimap<long long, int, greater<long long>> & mmap, long long key, int value) {
    auto range = mmap.equal_range(key);
    auto it = range.first;
    for (; it != range.second && it->second < value; ++it) {}
    mmap.insert(it, {key, value});
}

typedef struct apply{
    int u,v;
    long long x;
    int y;
    bool operator < (const apply &t) const{
        return y>t.y;
    }
}Apply;

priority_queue<Apply> applies;


void update_set(int u,int v,int x,bool flag =true){
    auto it = e[u].find(edges[{u,v}]);
    bool cant_find = true;
    for(;it!=e[u].end();it= next(it)){
        if(it->first!=edges[{u,v}]){
            break;
        }
        if(it->second==v){
            e[u].erase(it);
            if(edges[{u,v}]+x){
                orderedInsert(e[u],edges[{u,v}]+x,v);
            }
            cant_find = false;
            break;
        }
    }
    if(cant_find){
        orderedInsert(e[u],edges[{u,v}]+x,v);
    }
    if(flag){
        update_set(v,u,x,false);
    }
}

bool check(int u,int v=-1){
    if(v!=-1){
        return e[u].begin()->second == v && e[v].begin()->second == u;
    }
    return e[e[u].begin()->second].begin()->second == u;
}

int main(){
    scanf("%d%d",&n,&m);
    int day= 0;
    int alone = n;
    int cnt = 0;
    while(m--){
        while(applies.size() && applies.top().y==day){
            Apply t = applies.top();
            applies.pop();
            bool flag1= check(t.u,t.v),flag2 = check(t.u),flag3 = check(t.v);
            update_set(t.u,t.v,-t.x);
            edges[{t.u,t.v}] -= t.x;
            edges[{t.v,t.u}] -= t.x;
            if(e[t.u].size()==0){
                alone++;
            }
            if(e[t.v].size()==0) {
                alone++;
            }
//            cout<<"aaa"<<check(t.u,t.v)<<endl;
            if(!check(t.u,t.v)) {
                if (flag1) {
                    if (check(t.u) && check(t.v)) {
                        cnt += 1;
                    } else if (check(t.u) || check(t.v)) {
                    } else {
                        cnt -= 1;
                    }
                }else{
                    if(check(t.u) && !flag2){
                        cnt+=1;
                    }
                    if(check(t.v) && !flag3){
                        cnt+=1;
                    }
                }
            }
        }
        int k;
        scanf("%d",&k);
        while(k--){
            int u,v;
            long long x;
            int y;
            scanf("%d%d%lld%d",&u,&v,&x,&y);
            if(e[u].size()==0){
                alone--;
            }
            if(e[v].size()==0){
                alone--;
            }
            bool flag1 = check(u,v),flag2 = check(u),flag3 = check(v);
            update_set(u,v,x);
            if(check(u,v)){
                if(!flag1){
                    if(flag2 && flag3){
                        cnt-=1;
                    }
                    else if(flag2||flag3){
                    }
                    else{
                        cnt+=1;
                    }
                }
            }else{
                if(e[u].begin()->second == v && flag2){
                    cnt-=1;
                }
                if(e[v].begin()->second == u && flag3){
                    cnt-=1;
                }
            }
            edges[{u,v}] += x;
            edges[{v,u}] += x;
            applies.push({u,v,x,day+y});
        }
        int l;
        scanf("%d",&l);
        while(l--){
            int q;
            scanf("%d",&q);
            if(e[q].empty()){
                cout<<0<<endl;
                continue;
            }
            else{
                cout<<e[q].begin()->second<<endl;
            }
        }
        int p,q;
        scanf("%d%d",&p,&q);
        if(p){
            cout<<alone<<endl;
        }
        if(q){
//            cout<<"-------------------"<<endl;
//            for(int i=1;i<=n;i++){
//                cout<<i<<":"<<e[i].begin()->second<<endl;
//            }
//            cout<<"-------------------"<<endl;
            cout<<cnt<<endl;
        }
        day++;
    }
    return 0;
}

