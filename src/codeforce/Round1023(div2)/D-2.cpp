#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct T{
    int d,u,v;
    vector<int> path;
    bool operator <(const T& o) const {
        if(d != o.d) return d < o.d;
        if(u != o.u) return u < o.u;
        return v < o.v;
    }
};

vector<vector<int>> g;
vector<char> rm, vis;
vector<int> dis;
vector<int> fa;//记录路径

T get(int start){
    queue<int> q;
    vector<int> record;
    q.push(start);
    dis[start]=0;
    vis[start]=1;
    record.push_back(start);
    int a = start;
    while(!q.empty()){
        int t = q.front();q.pop();
        if(dis[t] > dis[a] || (dis[t] == dis[a] && t > a)) a = t;
        for(auto x:g[t]){
            if(!rm[x] && !vis[x]){
                vis[x]=1;
                dis[x]=dis[t]+1;
                q.push(x);
                record.push_back(x);
            }
        }
    }
    for(auto x:record) vis[x]=0;

    vector<int> record2;
    q.push(a);
    vis[a]=1;
    dis[a]=0;

    record2.push_back(a);
    int b = a;
    fa[a] = -1;
    while(!q.empty()){
        int t = q.front();q.pop();
        if(dis[t] > dis[b] || (dis[t] == dis[b] && t > b)) b = t;
        for(auto x:g[t]){
            if(!rm[x] && !vis[x]){
                vis[x]=1;
                dis[x]=dis[t]+1;
                fa[x]=t;
                q.push(x);
                record2.push_back(x);
            }
        }
    }
    for(auto x:record2) vis[x]=0;

    vector<int> path;
    for(int x = b; x != -1; x = fa[x]) path.push_back(x);
    return { (int)path.size(), max(a, b), min(a, b), path };
}

void init(int n){
    g.assign(n+1,{});
    rm.assign(n+1,0);
    vis.assign(n+1,0);
    dis.assign(n+1,0);
    fa.assign(n+1,-1);
}

void solve() {
    int n;
    cin>>n;
    init(n);
    for (int i = 0; i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<T> pq;

    pq.push(get(1));
    vector<T> ans;
    while(!pq.empty()){
        T t = pq.top();pq.pop();
        ans.push_back(t);
        for(auto x:t.path){
            rm[x]=1;
        }
        for(auto x:t.path){
            for(auto y:g[x]){
                if(!rm[y]){
                    pq.push(get(y));
                }
            }
        }
    }
    for(auto x:ans){
        cout<<x.d<<" "<<x.u<<" "<<x.v<<" ";
    }
    cout<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1023(div2)/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}