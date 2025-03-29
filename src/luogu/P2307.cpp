//
// Created by lyh on 2025/3/21.
//
#include <iostream>
#include "cstring"
using namespace std;
const int N = 1e5 + 10;
int fa[N],st[N];

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
    int a,b;
    for(int i=1;i<=N-1;i++){
        fa[i]=i;
    }
    bool flag = true;
    int sum=0;
    while(true){
        scanf("%d %d",&a,&b);
        if(a== -1 && b == -1){
            break;
        }
        if(a==0 && b==0) {
            if(flag && sum==1) {
                printf("1\n");
            }else{
                printf("0\n");
            }
            for(int i=1;i<=N-1;i++){
                fa[i]=i;
            }
            memset(st,0,sizeof st);
            flag = true;
            sum=0;
            continue;
        }
        int x = find(a),y = find(b);
        if(!st[a])sum++;
        if(!st[b])sum++;
        st[a]=st[b]=1;
        if(x==y){
            flag = false;
        }else{
            fa[x] = y;
            sum--;
        }
    }
}