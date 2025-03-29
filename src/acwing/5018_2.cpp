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
    char op=-1;
    int number1,number2;
}exprs[500010];

bool judge(user u,int idx){
    if(exprs[idx].op == 0){
        return judge(u,2*idx+1) && judge(u,2*idx+2);
    }else if(exprs[idx].op == 1){
        return judge(u,2*idx+1) || judge(u,2*idx+2);
    }else if(exprs[idx].op == 2){
        if(u.attrs.count(exprs[idx].number1) && u.attrs[exprs[idx].number1] == exprs[idx].number2){
            return true;
        }
    }else if(exprs[idx].op == 3){
        if(u.attrs.count(exprs[idx].number1) && u.attrs[exprs[idx].number1] != exprs[idx].number2){
            return true;
        }
        return false;
    }
    return false;
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
        exprs[idx].op = op==':'?2:3;
        exprs[idx].number1 = number1;
        exprs[idx].number2 = number2;
        return x;
    }
    return x;
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
        for(int i=1;i<=n;i++){
            if(judge(Users[i],0)){
                printf("%d ",Users[i].id);
            }
        }
        printf("\n");
        memset(exprs,0,sizeof exprs);
    }
}
