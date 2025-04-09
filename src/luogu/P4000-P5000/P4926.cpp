#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e6 + 5;
int n,s,t;
int h[N],e[N],ne[N],idx,type[N];
double w[N];
int q[N],st[N],cnt[N];
double dist[N];

void add(int a,int b,double c,int d){
    e[idx]=b;
    ne[idx] = h[a];
    w[idx]=c;
    type[idx] = d;
    h[a]=idx++;
}

bool spfa(double T){
    int hh=0,tt=1;
    memset(dist, -0x1f,sizeof dist);
    memset(cnt, 0,sizeof cnt);
    memset(st, 0,sizeof st);
    memset(q, 0,sizeof q);
    dist[0]=0;
    q[0]=0;
    st[0]=true;
    while(hh!=tt){
        int tq =q[--tt];
        st[tq] = false;
        for(int i=h[tq];i!=-1;i=ne[i]){
//            cout<<t<<":"<<i<<endl;
            int j = e[i];
            double wight;
            if(type[i] == 3) wight = w[i];
            else if(type[i] == 2) wight = -log2(w[i]+T);
            else wight = log2(w[i]-T);
            if(dist[j] < dist[tq] + wight){
                dist[j] = dist[tq] + wight;
                cnt[j] = cnt[tq] + 1;
                if(cnt[j] >= n+2) return true;//找不到一条路，说明肯定有人得女装
                if(!st[j]){
                    st[j] = true;
                    q[tt++] = j;
                }
            }
        }
    }
    return false; //找到了一条路，意味着满足所有人都不女装
}

double l=0,r=10;
void solve() {
    scanf("%d%d%d", &n, &s, &t);
    memset(h,-1,sizeof h);
    for(int i=1;i<=n+1;i++) add(0,i,0,3);
    for(int i=1;i<=s;i++){
        int o,A,B;
        double k;
        scanf("%d%d%d%lf",&o,&A,&B,&k);
        add(B,A,k,o);
//        if(o==1) r = min(r,(double)k);
    }
    for(int i=1;i<=t;i++){
        int C;
        double x;
        scanf("%d%lf",&C,&x);
        add(n+1,C,log2(x),3);
        add(C,n+1,-(log2(x)),3);
    }
    double ans=1;
    if(!spfa(0)) cout<<-1<<endl;
    else{
        while(r-l>1e-5){
//            cout<<ans<<"+";
            double mid = (l+r)/2.0;
            if(spfa(mid))  ans = mid,l = mid + 1e-5;
            else  r = mid - 1e-5;
        }
        printf("%.6f\n",ans);
    }
}

int main() {
    int work = 1;
#ifdef LOCAL
    freopen("src/luogu/P4000-P5000/in/P4926.in", "r", stdin);
#endif
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}