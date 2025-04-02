//
// Created by lyh on 2025/3/30.
//
//335597
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int n,m;
char map[1011][1011];
set<pair<int,int>, greater<>> G,H,safe;

int main(){
    freopen("src/luogu/T/in/T315529-5.in", "r", stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            map[i][j]=s[j-1];
            if(map[i][j]=='*'){
                safe.insert({i,j});
            }
            if(map[i][j] == 'G'){
              G.insert({i,j});
            }
            if(map[i][j] == 'H'){
                H.insert({i,j});
            }
        }
    }
    set<pair<int,int>, greater<>> G_bak=G,H_bak=H;

    if(safe.size() == 0){
        cout<<"War is Peace.";
    }else{
        cout<<safe.size();
    }
    fclose(stdin);
}
