#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 5,M = 3e5 + 5;
int n,k;

int h[N],e[M],ne[M],w[M],idx;
long long dist[N];
bool st[N];
int q[N],cnt[N];
bool spfa(){
    int hh=0,tt=1;
    memset(dist,-0x3f,sizeof dist);
    dist[0]=0;
    q[0]=0;
    st[0]=true;
    while(hh != tt){
        int t =q[--tt];
        st[t] = false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n+1) return false;
                if(!st[j]){
                    st[j] = true;
                    q[tt++] = j;
                }
            }
        }
    }
    return true;
}

void add(int a,int b,int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void solve() {
    long long ans=0;
    memset(h,-1,sizeof h);
    scanf("%d%d", &n, &k);
    for(int i=1;i<=k;i++){
        int x,a,b;
        scanf("%d%d%d",&x,&a,&b);
        if(x == 1) {
            add(a,b,0);
            add(b,a,0);
        } else if(x == 2) {
           add(a,b,1);
        } else if(x == 3) {
            add(b,a,0);
        } else if(x == 4) {
            add(b,a,1);
        } else if(x == 5) {
            add(a,b,0);
        }
    }
    for(int i= 1;i<=n;i++){
        add(0,i,1);
    }

    if(!spfa()){
        cout<<-1<<endl;
    }else{
        for(int i=1;i<=n;i++) ans+=dist[i];
        cout<<ans<<endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/acwing/in/1169.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}