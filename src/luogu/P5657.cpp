//
// Created by lyh on 2025/2/26.
//
#include <iostream>
#include "cmath"
using namespace std;

//
//int * grayCode(int n){
//    if (n==1){
//        int* res = new int[2]{0, 1};
//        return res;
//    }
//    int *last = grayCode(n-1);
//    int* res = new int[int(pow(2, n))];
//    for (int i = 0; i < int(pow(2,n-1)); ++i) {
//        res[i] = last[i];
//    }
//    for (int i = int(pow(2,n-1)); i < int(pow(2,n)); ++i) {
//        res[i] = last[int(pow(2,n))-i-1]+int(pow(2,n-1));
//    }
//    return res;
//}

//int main(){
//    int n,k;
//    cin>>n>>k;
//    int *res = grayCode(n);
//   //输出第k个二进制
//    for (int i = 0; i < n; ++i) {
//        cout<<((res[k]>>i)&1);
//    }
//    return 0;
//}

void graycode(int n, unsigned long long k){
    if (n==1){
        cout<<k;
        return;
    }
    if(k< pow(2,n-1)){
        cout<<0;
        graycode(n-1, k);
    } else{
        cout<<1;
        if(n==64){
            unsigned long long tmp = 18446744073709551615ull;
            graycode(n-1, tmp-k);
            return;
        }
        unsigned long long tmp = pow(2,n);
        graycode(n-1, tmp-k-1);
    }
}

int main(){
    int n;
    unsigned long long k;
    cin>>n>>k;
    graycode(n, k);
    return 0;
}

