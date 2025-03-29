//
// Created by lyh on 2025/3/28.
//
#include<iostream>
#include<cstring>
const int N = 1e5+10;
using namespace std;
long long divide(long long x,int k){
    long long ans=x;
    for(int i=2;i<=x/i;i++){
        if(x%i==0){
            int s=0;
            while(x%i==0){
                x/=i;
                s++;
            }
            if(s<k){
                while(s--){
                    ans/=i;
                }
            }
        }
    }
    if(x>1) if(1<k) ans/=x;
    return ans;
}

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        long long x,k;
        scanf("%lld%d",&x,&k);
        cout<<divide(x,k)<<endl;
    }
}