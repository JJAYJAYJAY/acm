//
// Created by lyh on 2025/3/29.
//
#include<iostream>

using namespace std;
const int N =1e4+10;
int n,m,t;

int all[N];
int p,q;

void T(){
    int temp[q][p];
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            temp[j][i]=all[i*q+j];
        }
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<p;j++){
            all[i*p+j]=temp[i][j];
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    p=n,q=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            all[i*m+j]=x;
        }
    }
    while(t--){
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        if(op==1) {
            p = a;
            q = b;
        }
        if(op==2){
            T();
            swap(p,q);
        }
        if(op==3){
            cout<<all[a*q+b]<<endl;
        }
    }
}