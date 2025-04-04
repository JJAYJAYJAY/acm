//
// Created by lyh on 2025/4/3.
//
#include <iostream>
#include <set>
using namespace std;
const int N=2e5+5;
int n,k;
long long cost;

struct monster{
    int x;
    long long h;
    bool operator < (const monster &b) const{
        return h<b.h;
    }
};

multiset<monster> m;

struct node{
    int x;
    long long max;
    bool operator < (const node &b) const{
        return x<b.x;
    }
};

void solve(){
    scanf("%d%d",&n,&k);


};

int main(){
#ifdef LOCAL
    freopen("src/luogu/NOISG-2025-Finals-Unofficial-Mirror/in/T593208-1.in","r",stdin);
#endif
    int work=3;
    while(work--){
        solve();
    }

#ifdef LOCAL
    fclose(stdin);
#endif
}