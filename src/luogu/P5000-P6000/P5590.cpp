#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 5;

int n,m;
int h1[N],e1[N],ne1[N],idx1,w1[N];
int h2[N],e2[N],ne2[N],idx2;
int h3[N],e3[N],ne3[N],idx3;
int st[N],cnt[N],q[N];
int dist[N];
int x[N],y[N];
void add1(int a,int b,int c){
    e1[idx1] = b;
    ne1[idx1] = h1[a];
    w1[idx1] = c;
    h1[a] = idx1++;
}

void add2(int a,int b){
    e2[idx2]=b;
    ne2[idx2]= h2[a];
    h2[a]=idx2++;
}

void add3(int a,int b){
    e3[idx3]=b;
    ne3[idx3]= h3[a];
    h3[a]=idx3++;
}

bool spfa(){
    int hh=0,tt=1;
    memset(dist, 0x3f,sizeof dist);
    dist[1]=0;
    q[0]=1;
    st[1]=true;
    while(hh!=tt){
        int t =q[--tt];
        st[t] = false;
        for(int i=h1[t];i!=-1;i=ne1[i]){
//            cout<<t<<":"<<i<<endl;
            int j = e1[i];
//            cout<<t<<":"<<j<<":"<<(dist[j] < dist[t] + w1[i])<<endl;
            if(dist[j] > dist[t] + w1[i]){
                dist[j] = dist[t] + w1[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return false;
                if(!st[j]){
                    st[j] = true;
                    q[tt++] = j;
                }
            }
        }
    }
    return true;
}
int vis1[N],vis2[N];
void dfs(int x){
    vis1[x]=1;
//    if(x==n){
//        return;
//    }
    for(int i = h2[x];i!=-1;i=ne2[i]) {
        int to = e2[i];
        if(vis1[to]) continue;
        vis1[to] = 1; dfs(to);
    }
}

void ndfs(int x){
    vis2[x]=1;
//    if(x==1){
//        return;
//    }
    for(int i = h3[x];i!=-1;i=ne3[i]) {
        int to = e3[i];
        if(vis2[to]) continue;
        vis2[to] = 1; ndfs(to);
    }
}

void solve() {
    scanf("%d%d",&n,&m);
    memset(h1,-1,sizeof h1);
    memset(h2,-1,sizeof h2);
    memset(h3,-1,sizeof h3);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add2(a,b);
        add3(b,a);
        x[i]=a;
        y[i]=b;
    }
    dfs(1);
    ndfs(n);
//    for(int i=1;i<=n;i++){
//       cout<<vis1[i]<<" "<<vis2[i]<<endl;
//    }
    if(vis1[n]==0){cout<<"-1"<<endl;return;}
    for(int i=1;i<=m;i++){
        if(vis1[x[i]] && vis2[y[i]] && vis1[y[i]] && vis2[x[i]]) {
            add1(x[i],y[i],9);
            add1(y[i],x[i],-1);
        }
    }
    if(!spfa()) {cout<<"-1"<<endl;}
    else {
        cout<<n<<" "<<m<<endl;
        for(int i=1;i<=m;i++){
            if(vis1[x[i]] && vis2[y[i]] && vis1[y[i]] && vis2[x[i]]) {
                cout<<x[i]<<" "<<y[i]<<" "<<dist[y[i]]-dist[x[i]]<<endl;
            }else{
                cout<<x[i]<<" "<<y[i]<<" "<<1<<endl;
            }

        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P5000-P6000/in/P5590.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}