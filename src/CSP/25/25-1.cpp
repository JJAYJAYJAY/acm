//
// Created by lyh on 2025/3/28.
//
#include<iostream>

using namespace std;

const int N = 1e5+10;
int st[N];
int n,k;
int main(){
    st[0]=1;
    int ans=0;
    scanf("%d%d",&n,&k);

    while(k--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(!st[y]){
            ans++;
        }
        st[x]=1;
    }
    printf("%d\n",ans);
}