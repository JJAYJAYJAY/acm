//
// Created by lyh on 2025/3/23.
//
#include <iostream>
#include<cstring>
using namespace std;

int st[128];

int main(){
    int n;
    cin>>n;
    while(n--){
        memset(st,0,sizeof st);
        bool flag1=true,flag2=false,flag3=false,flag4=false;
        string str;
        cin>>str;
        for(int i=0;str[i];i++){
            if(st[str[i]]<2){
                st[str[i]] +=1;
            }else{
                flag1=false;
            }
            if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')){
                flag2 =true;
            }
            if((str[i]>='0'&&str[i]<='9')){
                flag3=true;
            }
            if((str[i]=='*'||str[i]=='#')){
                flag4=true;
            }
        }
        if(flag1){
            if(flag2&&flag3&&flag4){
                cout<<2<<endl;
                continue;
            }
            cout<<0<<endl;
        }else{
            if(flag2&&flag3&&flag4){
                cout<<1<<endl;
                continue;
            }
            cout<<0<<endl;
        }
    }
}