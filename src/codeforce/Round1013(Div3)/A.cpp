//
// Created by lyh on 2025/4/3.
//
#include <iostream>
#include <map>
using namespace std;

map<int,int> mp;

void init(){
    mp.clear();
    mp.insert({0,3});
    mp.insert({3,1});
    mp.insert({1,1});
    mp.insert({2,2});
    mp.insert({5,1});
}

int n;
int main(){
#ifdef LOCAL
    freopen("src/codeforce/Round1013(Div3)/in/A.in","r",stdin);
#endif
    scanf("%d",&n);
    while(n--){
        int m,cnt=0;
        scanf("%d",&m);
        init();
        while(!mp.empty()&&m--){
            int x;
            scanf("%d",&x);
            if(mp.count(x)){
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
            }
            cnt++;
        }
        if(mp.empty()) printf("%d\n",cnt);
        else printf("0\n");
        if(m>0) while(m--) scanf("%d",&cnt);
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}