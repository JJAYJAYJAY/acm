//
// Created by lyh on 2025/4/3.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
const int N=2e5+5;
int n,k;
long long cost;

struct monster{
    int x;
    long long h;
    bool operator < (const monster &b) const{
        return x<b.x;
    }
};

vector<monster> m;

struct node{
    int x;
    long long cnt;
    bool operator < (const node &b) const{
        return x<b.x;
    }
};
set<node> v;
void solve(){
    cost =0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int x,h;
        scanf("%d%d",&x,&h);
        m.push_back({x,h});
    }
    sort(m.begin(),m.end());
    for(int i=1;i<=k;i++){
        int x;
        scanf("%d",&x);
        v.insert({x,0});
    }
    for(int i=0;i<n;i++){
        auto lower_it= v.lower_bound({m[i].x,0});
        auto upper_it= v.upper_bound({m[i].x,0});
        int dis1=1e9,dis2=1e9;
        if(lower_it!=v.begin()){
            dis1 = abs(prev(lower_it)->x - m[i].x);
            cout<<"dis1: "<<dis1<<endl;
        }
        if(upper_it!=v.end()){
            dis2 = abs(upper_it->x - m[i].x);
            cout<<"dis2: "<<dis2<<endl;
        }
        if(dis1>=dis2){
            if(upper_it->cnt==0) {
                if(m[i].h<dis2+1) {
                    cost += m[i].h;
                }else{
                    node tmp = *upper_it;
                    tmp.cnt = 1;
                    v.erase(upper_it);
                    v.insert(tmp);
                    cost++;
                    cost+= dis2;
                }
            }else{
                if(m[i].h<dis2) {
                    cost += m[i].h;
                }else{
                    cost+= dis2;
                }
            }
        }else{

            if(lower_it->cnt==0) {
                if(m[i].h<dis1+1) {
                    cost += m[i].h;
                }else{
                    node tmp = *prev(lower_it);
                    tmp.cnt = 1;
                    v.erase(lower_it);
                    v.insert(tmp);
                    cost++;
                    cost+= dis1;
                }
            }else{
                if(m[i].h<dis1) {
                    cost += m[i].h;
                }else{
                    cost+= dis1;
                }
            }
        }
    }
    cout<<cost<<endl;
};

int main(){
#ifdef LOCAL
    freopen("src/luogu/contest/NOISG-2025-Finals-Unofficial-Mirror/in/T593208-1.in","r",stdin);
#endif
    int work=3;
    while(work--){
        solve();
    }

#ifdef LOCAL
    fclose(stdin);
#endif
}