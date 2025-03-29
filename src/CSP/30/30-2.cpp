//
// Created by lyh on 2025/3/29.
//
#include<iostream>
#include <vector>
using namespace std;
const int N = 1e4+10;

int n,m;

struct Matrix{
    vector<long long> v[N];
    int n,m;
    Matrix(int n,int m):n(n),m(m){}
    void init(){
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                v[i].push_back(0);
    }
    Matrix operator* (const Matrix B) const {
        Matrix C(n,B.m);			//用来存放答案
        C.init();
        for(int i = 0;i < n;i++)
            for(int j = 0;j < B.m;j++)
                for(int k = 0;k < m;k++)
                    C.v[i][j] += v[i][k]*B.v[k][j];
        return C;
    }
    void print(){//输出该矩阵，用来测试
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
    }
    //求转置矩阵
    Matrix T(){
        Matrix C(m,n);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                C.v[j].push_back(v[i][j]);
        return C;
    }
};


vector<long long> W;

int main(){
    scanf("%d%d",&n,&m);
    Matrix Q(n,m),K(n,m),V(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long x;
            scanf("%lld",&x);
            Q.v[i].push_back(x);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long x;
            scanf("%lld",&x);
            K.v[i].push_back(x);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long x;
            scanf("%lld",&x);
            V.v[i].push_back(x);
        }
    }
    for(int i=0;i<n;i++){
        long long x;
        scanf("%lld",&x);
        W.push_back(x);
    }

    Matrix res = K.T()*V;
    res = Q * res;
//    res.print();
    for(int i=0;i<res.n;i++){
        for(int j=0;j<res.m;j++){
            res.v[i][j] *= W[i];
        }
    }
//    res.print();
    res.print();
}