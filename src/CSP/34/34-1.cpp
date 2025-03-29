//
// Created by lyh on 2025/3/29.
//
#include<iostream>

using namespace std;
const int N =1e4+10;
int n,m,p,q;

int all[N];

int main(){
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            all[i*m+j]=x;
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cout<<all[i*q+j]<<" ";
        }
        cout<<endl;
    }
}