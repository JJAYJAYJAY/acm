//
// Created by lyh on 2025/4/5.
//
#include <iostream>
#include <deque>
using namespace std;


int n,m;
int f[500005];

void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        f[i] = f[i-1]+x;
    }
    deque<int> q;
    q.push_back(0);
    int ans=-233333333;
    for(int i=1;i<=n;i++){
        while(q.front()+m<i)
            q.pop_front();
        ans=max(ans,f[i]-f[q.front()]);
        while(!q.empty()&&f[q.back()]>=f[i])
            q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",ans);
}


int main(){
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1714.in","r",stdin);
#endif
    int work=1;
    while(work--){
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}