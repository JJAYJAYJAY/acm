//
// Created by lyh on 2025/4/8.
//
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define inf 0x7f7f7f7f
#define Maxn 5005
int n,s,t,tot;
int cnt[Maxn],hea[Maxn],nex[Maxn*2],ver[Maxn*2],typ[Maxn*2];
double ds[Maxn],edg[Maxn*2];
bool inq[Maxn];

inline void add(int x,int y,double d,int Type)
{
    ver[++tot]=y,edg[tot]=d,typ[tot]=Type,nex[tot]=hea[x],hea[x]=tot;
}

bool spfa(double tmp) // tmp 这里表示上面说的 t 的值
{
    for(int i=0;i<=n;i++) ds[i]=-inf,cnt[i]=0,inq[i]=false; ds[n+1]=0;
    queue<int> q; q.push(n+1),inq[n+1]=true;
    while(!q.empty())
    {
        int cur=q.front(); q.pop(),inq[cur]=false;
        for(int i=hea[cur];i;i=nex[i])
        {
            double w=edg[i]; // 类型为 3 的边
            if(typ[i]==1) w=log2(edg[i]-tmp); // 类型为 1 的边
            if(typ[i]==2) w=-log2(edg[i]+tmp); // 类型为 2 的边
            if(ds[ver[i]]<ds[cur]+w)
            {
                ds[ver[i]]=ds[cur]+w,cnt[ver[i]]=cnt[cur]+1;
                if(cnt[ver[i]]>=n+2) return true; // 判断无解
                else if(!inq[ver[i]]) inq[ver[i]]=true,q.push(ver[i]);
            }
        }
    }
    return false; // 此时有解
}

double x,l=0,r=10,ans,mid;
double cha = 0.00001;
int main(){
    scanf("%d%d%d",&n,&s,&t);
    for(int i=0;i<=n;i++) add(n+1,i,0,3);
    for(int i=1,opt,a,b;i<=s;i++)
    {
        scanf("%d%d%d%lf",&opt,&a,&b,&x),add(b,a,x,opt);
//        if(opt==1) r=fmin(r,x);
    }
    for(int i=1,c;i<=t;i++) scanf("%d%lf",&c,&x),add(0,c,log2(x),3),add(c,0,-log2(x),3);
    if(!spfa(0)) printf("-1\n");
    else
    {
        while(r-l>cha) // cha 是 0.00001 保证精度
        {
            mid=(l+r)/2.0;
            if(spfa(mid)) ans=mid,l=mid+cha;
            else r=mid-cha;
        }
        printf("%.6lf\n",ans);
    }
}
