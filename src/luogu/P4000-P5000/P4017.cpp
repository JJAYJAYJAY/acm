//
// Created by lyh on 2025/3/21.
//
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=5e5+10;
const int MOD=80112002;
int h[N],e[N],ne[N],idx;
int deg[N];
long long dp[5010];
int n,m;

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
    deg[b]++;
}

long long solve(){
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
            dp[i]=1;
        }
    }

    while(q.size()){
        int t =q.front();
        q.pop();

        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            dp[j]+=dp[t];
            dp[j]%=MOD;
            if(--deg[j]==0){
                q.push(j);
            }
        }
    }
    long long res=0;
    for(int i=1;i<=n;i++){
        if(h[i]==-1){
            res+=dp[i]%MOD;
        }
    }
    return res%MOD;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    cout<<solve()<<endl;

}