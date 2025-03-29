//
// Created by lyh on 2025/3/25.
//
#include <iostream>
#include <cstring>

const int N=1e5+10;
using namespace std;
int n;
int a[N],b[N],k[N],s[N];
int maxs[N],pre_max[N]; // i ~ n+1的最大值,0~i的最大值

int main(){
    memset(maxs,-0x3f3f3f3f, sizeof maxs);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        k[i] = a[i-1]-b[i-1];
        s[i] = s[i-1]+k[i];
    }
    k[n+1] = a[n]-b[n];
    s[n+1] = s[n]+k[n+1];
    for(int i =n+1;i>=1;i--){
        maxs[i] = max(maxs[i+1],s[i]);
    }
    for(int i=1;i<=n;i++){
        pre_max[i] = max(pre_max[i-1],s[i]);
    }

    for(int i=1;i<=n;i++){
        cout<<(maxs[i+1]+b[i]>pre_max[i]?maxs[i+1]+b[i]:pre_max[i])<<" ";
    }
}