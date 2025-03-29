//
// Created by lyh on 2025/3/25.
//
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N =1e5+10;

int b[N],st[N];
int n,a[N],k[N];
int dist[N];

int dijkstra(){
    priority_queue<pair<int,int>> heap;
    memset(dist,0x3f3f3f3f, sizeof dist);
    dist[1] =0;
    int pos = 0;
    heap.push({0,1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second,d = -t.first;
        if(st[ver]) continue;
        st[ver] = 1;
        if(ver+k[ver]<=pos) continue;
        for(int i = max(pos,ver+1);i<=min(n,ver+k[ver]);i++){
            if(i==n){
                return d+1;
            }
            int j = b[i];
            if(dist[j]>d+1){
                dist[j] = d+1;
                heap.push({-dist[j],j});
            }
        }
        pos = max(pos,ver+k[ver]);
    }
    return -1;
}

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i] =  i - a[i];
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&k[i]);
    }
    cout<<dijkstra();
}
