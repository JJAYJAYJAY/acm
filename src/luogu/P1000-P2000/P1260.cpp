#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4 + 5;

int n,m;

int h[N],w[N],e[N],ne[N],idx;
int dist[N];
int q[N],st[N],cnt[N];
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a]=idx++;
}

bool spfa(){
    int hh=0,tt=1;
    memset(dist,0x3f,sizeof dist);
    memset(st, 0,sizeof st);
    dist[0]=0;
    q[0]=0;
    st[0]=true;
    while(hh != tt){
        int t =q[--tt];
        st[t] = false;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
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

void solve() {
    idx=0;
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(b,a,c);
    }
    for(int i=1;i<=n;i++){
        add(0,i,0);
    }
    if(!spfa()){
        cout<<"NO SOLUTION"<<endl;
    }else{
        int minn= 0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            minn = min(minn,dist[i]);
        }
        for(int i=1;i<=n;i++){
            cout<<dist[i]-minn<<endl;
        }
    }
}

int main() {
    int work = 1;
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1260.in", "r", stdin);
    work = 2;
#endif
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}