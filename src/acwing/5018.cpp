//
// Created by lyh on 2025/3/14.
//
#include <iostream>
#include <unordered_map>
#include <set>
#include <cstring>

using namespace std;
struct user{
    int id;
    unordered_map<int,int> attrs;
}Users[2510];

int n,m;
struct expr{
    set<int> val;
    int op=-1;

}exprs[500010];

set<int> calc(char op,int a,int b){
    set<int> res;
    if(op == ':'){
        for(int i=1;i<=n;i++){
            if(Users[i].attrs.count(a) && Users[i].attrs[a] == b){
                res.insert(Users[i].id);
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(Users[i].attrs.count(a) && Users[i].attrs[a] != b){
                res.insert(Users[i].id);
            }
        }
    }
    return res;
}

int build(string str,int x=0 ,int idx=0){
    while(str[x]=='('||str[x]==')') x++;
    if(str[x] == '&' || str[x] == '|'){
        if(str[x] == '&') exprs[idx].op = 0;
        else exprs[idx].op = 1;
        x = build(str,x+1,2*idx+1);
        x = build(str,x+1,2*idx+2);
    }else{
        int start = x;
        int number1,number2;
        char op;
        for(;str[x]!=')'&&x<str.length();x++){
            if(str[x]==':'||str[x]=='~'){
                op = str[x];
                number1 = stoi(str.substr(start,x-start));
                start = x+1;
            }
        }
        number2 = stoi(str.substr(start,x-start));
        exprs[idx].val=calc(op,number1,number2);
        exprs[idx].op = -1;
        return x;
    }
    return x;
}

set<int> count(int idx){
    if(exprs[idx].op==-1) return exprs[idx].val;
    set<int> res;
    set<int> left = count(2*idx+1);
    set<int> right = count(2*idx+2);
    if(exprs[idx].op == 0){
        for(auto x:left){
            if(right.count(x)) res.insert(x);
        }
    }else{
        for(auto x:left) res.insert(x);
        for(auto x:right) res.insert(x);
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int id;
        scanf("%d",&id);
        Users[i].id = id;
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            Users[i].attrs[a] = b;
        }
    }

    scanf("%d",&m);
    while(m--){
        string op;
        cin>>op;
        build(op);
        set<int> res = count(0);
        if(res.size() == 0) {
            puts("");
        }else{
            for(auto x:res){
                printf("%d ",x);
            }
            puts("");
        }
        memset(exprs,0,sizeof exprs);
    }
}
