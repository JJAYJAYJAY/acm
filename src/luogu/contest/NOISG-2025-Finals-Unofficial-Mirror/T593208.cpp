//
// Created by lyh on 2025/4/3.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
long long cost;

struct monster{
    long long x;
    long long h;
    bool operator < (const monster &b) const{
        return x<b.x;
    }
};

vector<monster> m;

struct node{
    long long x;
    long long cnt;
    bool operator < (const node &b) const{
        return x<b.x;
    }
};
vector<node> v;
void solve(){
    v.clear();
    m.clear();
    cost =0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        long long x,h;
        scanf("%lld%lld",&x,&h);
        m.push_back({x,h});
    }
    sort(m.begin(),m.end());
    v.push_back({-2000000007,0});
    for(int i=1;i<=k;i++){
        int x;
        scanf("%d",&x);
        v.push_back({x,0});
    }
    sort(v.begin() + 1,v.end());
    v.push_back({2000000007,0});
    for(int i=0;i<n;i++){
        auto it = lower_bound(v.begin() + 1,v.end(), (node){m[i].x,0});
        int l = it - v.begin() - 1;
        int r = it - v.begin();
        long long d1 = m[i].x - v[l].x;
        long long d2 = v[r].x - m[i].x;
//        cout<<"d1:"<<d1<<" d2:"<<d2<<endl;
        if(m[i].h<=min(d1,d2)){
            cost += m[i].h;
            continue;
        }
        if(d1==d2){
            if(v[l].cnt == 1){
                cost += d1;
            }else{
                if(v[r].cnt == 0){
                    v[r].cnt = 1;
                    cost ++;
                }
                cost += d2;
            }
        }else{
            if(d1>d2){
                cost += d2;
                if(v[r].cnt == 0){
                    v[r].cnt = 1;
                    cost++;
                }
            }else{
                cost += d1;
                if(v[l].cnt == 0){
                    v[l].cnt = 1;
                    cost++;
                }
            }
        }
    }
    cout<<cost<<endl;
};

int main(){
#ifdef LOCAL
    freopen("src/luogu/contest/NOISG-2025-Finals-Unofficial-Mirror/in/T593208-2.in","r",stdin);
#endif
    int work=1;
    while(work--){
        solve();
    }

#ifdef LOCAL
    fclose(stdin);
#endif
}