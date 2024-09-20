//
// Created by lyh on 2024/9/20.
//
#include "iostream"
#include "cstring"
#include "stack"
using namespace std;

string str;
int i;
string read(int& i){
    string res;
    char c;
    while(i<str.size()){
        c=str[i++];
        if(c=='['){
            int n=0;
            while(str[i]>='0'&&str[i]<='9'){
                n = n*10 + str[i++]-'0';
            }
            string s = read(i);
            while(n--){
                res+=s;
            }
        } else{
            if(c==']'){
                return res;
            } else{
                res+=c;
            }
        }
    }
    return res;
}

int main(){
    cin>>str;
    i=0;
    cout<<read(i);
}