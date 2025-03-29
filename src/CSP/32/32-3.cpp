//
// Created by lyh on 2025/3/28.
//
#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2010;
int h[N],e[N],ne[N],idx;
int p[N];
long long nodes_w[N];
bool st[N]; //节点是否被删除
int root=1;//当前的根节点
long long ww[N];

int n,m;

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void update_ww(int child){
    for(int i=p[child];i!=0;i=p[i]){
        ww[i]+=ww[child];
    }
}

void delete_ww(int child){
    for(int i=p[child];i!=0;i=p[i]){
        ww[i]-=ww[child];
    }
}

bool dfs_find(int r,int target){
    for(int i=target;i!=0;i=p[i]){
        if(i==r) return true;
    }
    return false;
}
struct node{
    int id;
    long long num;
    bool operator < (const node &t) const{
        if(num == t.num){
            return id<t.id;
        }
        return num<t.num;
    }
};
node find_min_ww(int r){
    node min_ww={r,abs(ww[root] - ww[r] - ww[r])};
//    cout<<"r:"<<r <<" min_ww:"<<min_ww.num<<endl;
    for(int i=h[r];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]) min_ww = min(min_ww,find_min_ww(j));
    }
    return min_ww;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        scanf("%lld",&nodes_w[i]);
        ww[i] = nodes_w[i];
    }
    for(int i=2;i<=n;i++){
        int parent;
        scanf("%d",&parent);
        p[i] = parent;
        add(parent,i);
        update_ww(i);
    }
    long long ww_bak[N];
    memcpy(ww_bak,ww,sizeof ww);
    while(m--){
        memset(st,false,sizeof st);
        memcpy(ww,ww_bak,sizeof ww);
        int q;
        root=1;
        scanf("%d",&q);
        while(true){
            int fl=true;
            for(int i=h[root];i!=-1;i=ne[i]){
                if(!st[e[i]]) fl=false;
            }
            if(fl) break;
            int min_node = find_min_ww(root).id;
//            cout<<"st[4]:"<<st[4]<<" root:"<<root<<" total:"<<total<<" "<<min_node<<endl;
            cout<<min_node<<" ";
            if(dfs_find(min_node,q)){
                root = min_node;
            }else{
                delete_ww(min_node);
                st[min_node] = true;
            }
        }
        cout<<endl;
    }
}