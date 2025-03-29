//
// Created by lyh on 2025/3/12.
//
#include <iostream>
#include <set>
#include <map>

using namespace std;

map<int,int> mp;
int c,m,n;
void check(int x){
    int l=-1,r=-1;
    if(mp.size() == 0 || mp.count(x) == 0) return;
    if(mp[x]>=5){
        mp.erase(x);
        if(x!=1 && mp.size() != 0){
            auto it = mp.lower_bound(x);
            if(it!=mp.begin()){
                mp[prev(it)->first]++;
                l=prev(it)->first;
            }
        }
        if(x!=c && mp.size() != 0){
            auto it = mp.upper_bound(x);
            if(it!=mp.end()) {
                mp[it->first]++;
                r = it->first;
            }
        }
        check(l);
        check(r);
    }
}

int main(){

    scanf("%d%d%d",&c,&m,&n);
    while(m--){
        int x,w;
        scanf("%d%d",&x,&w);
        mp[x]=w;
    }

    while(n--){
        int p;
        scanf("%d",&p);
        if(!mp.count(p)){
            mp[p]=1;
            printf("%lld\n",mp.size());
        }else{
            mp[p]+=1;
            check(p);
            printf("%lld\n",mp.size());
        }
    }
}