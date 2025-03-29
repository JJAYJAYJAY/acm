//
// Created by lyh on 2025/3/29.
//
#include<iostream>
#include<unordered_map>

using namespace std;

const int N=110;

unordered_map<string,int> cnt;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string mp;
        for(int j=1;j<=8;j++){
            string s;
            cin>>s;
            mp+=s;
        }
        cnt[mp]++;
        cout<<cnt[mp]<<endl;
    }
}