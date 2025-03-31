//
// Created by lyh on 2025/3/21.
//
#include "iostream"

using namespace std;
const int N = 3e5 + 10;

int h[N],e[N],ne[N],idx;
long long w[N];

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}


int main(){

}