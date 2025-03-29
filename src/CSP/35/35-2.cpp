//
// Created by lyh on 2025/3/23.
//
#include <iostream>
#include <cstring>

using namespace std;

int ne[128];

int n,m;

void add(int a,int b){
    ne[a]=b;
}

char find(int c,long long x){
    int res = c;
    int cnt = 0;
    for(int i=0;i<x;i++){
        cnt++;
        if(ne[res]==res){
            break;
        }
        if(ne[res]==c){
            int tmp = x % cnt;
//            cout<<cnt<<endl;
            res=c;
            for(int j=0;j<tmp;j++){
                res = ne[res];
            }
            return res;
        }
        res = ne[res];
    }
    return res;
}

int main(){
    for(int i=0;i<128;i++){
        ne[i]= i;
    }
    string str;
    getline(cin,str);
    cin>>n;
    string str1;
    getline(cin,str1);
    while(n--){
        getline(cin,str1);
        char x = str1[1];
        char y = str1[2];
        add(x,y);
    }
    scanf("%d",&m);
    while(m--){
        long long x;
        cin>>x;
        cout<<"#";
        for(int i =1;i<str.length()-1;i++){
            cout<<char(find(str[i],x));
        }
        cout<<"#"<<endl;
    }
}