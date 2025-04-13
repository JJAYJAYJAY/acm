#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N =110,M =1e5+10;
int n,p;

int c[N],u[N];

int h[M],e[M],ne[M],idx,w[M],indeg[N],outdeg[N];

void add(int a,int b,int x){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx]=x;
    indeg[b]++;
    outdeg[a]++;
    h[a]=idx++;
}
void top(){
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indeg[i] == 0) {
            q.push(i);
            u[i]=0;
        }
    }
    while(q.size()){
        int t = q.front();q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(c[t]-u[t]>0) {
                c[j] += w[i] * (c[t] - u[t]);
            }
            if(--indeg[j] == 0) q.push(j);
        }
    }
}
vector<int> out;
void solve() {
    scanf("%d%d", &n, &p);
    memset(h,-1,sizeof h);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i],&u[i]);
    }

    for(int i=1;i<=p;i++){
        int a,b,x;
        scanf("%d%d%d",&a,&b,&x);
        add(a,b,x);
    }
    top();
    for(int i=1;i<=n;i++){
        if(outdeg[i]==0 && c[i]-u[i]>0){
            out.push_back(i);
        }
    }
    if(!out.empty()){
        for(auto item:out){
            if(c[item]-u[item]>0){
                cout<<item<<" "<<c[item]-u[item]<<endl;
            }
        }
    }else{
        cout<<"NULL"<<endl;
    }

}

int main() {
#ifdef LOCAL
    freopen("src/luogu/P1000-P2000/in/P1038.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}