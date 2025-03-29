//
// Created by lyh on 2025/2/27.
//
#include <bits/stdc++.h>
using namespace std;
#define lng long long
const int N=5e5+10;
int n,fa[N];
struct brack{ //括号，f表示左右，d表示节点编号
    bool f;
    int d;
}bra[N];
char inp[N];
lng ans,dp[N],lst[N];
struct edge{ //树上加边
    int adj,nex;
}e[N];
int g[N],top;
void add(int x,int y){
    e[++top]=(edge){y,g[x]};
    g[x]=top;
}
stack<brack> s;
void dfs(int x){
    int tmp; //维护回溯
    if(s.empty()){ //RT
        tmp=x,s.push(bra[x]);
        dp[x]=dp[fa[x]];
        lst[x]=0;
    } else if(s.top().f==1&&bra[x].f==0){ //RT
        int fs=s.top().d;
        tmp=-fs,s.pop();
        lst[x]=lst[fa[fs]]+1;
        if(s.empty()){
            dp[x]=1LL+dp[fa[x]]-dp[fs]+dp[fa[fs]]+lst[fa[fs]];
        } else {
            int rs=s.top().d;
            dp[x]=dp[fa[rs]]+1+dp[fa[x]]-
                  dp[fs]+dp[fa[fs]]-dp[rs]+lst[fa[fs]];
        }
    } else { //RT
        tmp=x,s.push(bra[x]);
        dp[x]=dp[fa[x]];
        lst[x]=0;
    }
    for(int i=g[x];i;i=e[i].nex)
        dfs(e[i].adj); //递归
    if(tmp>0) s.pop();
    else s.push(bra[-tmp]);
    //★别☆忘★回☆溯★
}
int main(){
    scanf("%d\n%s",&n,inp+1);
    for(int i=1;i<=n;i++)
        bra[i]=(brack){(inp[i]=='('),i};
    for(int i=2;i<=n;i++){
        scanf("%d",fa+i);
        add(fa[i],i);
    }
    dfs(1); //dfs
    for(int i=1;i<=n;i++)
        ans^=dp[i]*i; //不用异或见祖宗
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }

    printf("%lld\n",ans); //不开long long见祖宗
    return 0;
}