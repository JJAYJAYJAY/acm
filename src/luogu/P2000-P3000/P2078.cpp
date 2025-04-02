//
// Created by lyh on 2025/4/1.
//
#include <iostream>
#include<cmath>
#include <cstring>

using namespace std;
const int N = 4e4+10;
int f[N],w[N];

int n,m,p,q;

int find(int x){
    if(f[x]!=x){
        f[x] = find(f[x]);
    }
    return f[x];
}

int main(){
#ifdef LOCAL
    freopen("src/luogu/P2000-P3000/in/P2078.in","r",stdin);
#endif
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=1;i<=n+m;i++) f[i]=i,w[i]=1;
    while(p--){
        int x,y;
        scanf("%d%d",&x,&y);
        int fx = find(x),fy = find(y);
        if(fx!=fy){
            f[fx] = fy;
            w[fy]+=w[fx];
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        x=(m+x)+n+1,y=(m+y)+n+1;
        int fx = find(x),fy = find(y);
        if(fx!=fy){
            f[fx] = fy;
            w[fy]+=w[fx];
        }
    }
    int fa = find(1),fb = find(m+n);
    cout<<min(w[fa],w[fb])<<endl;
#ifdef LOCAL
    fclose(stdin);
#endif
    return 0;
}