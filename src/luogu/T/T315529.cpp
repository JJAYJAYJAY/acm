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
    for(auto h:H){
        int j=h.second;
        for(int i=h.first-1;i>=1;i--){
            if(map[i][j]=='G' && (map[i+1][j]!='Z' && map[i-1][j]!='Z')){
//                if(!G_bak.erase({i,j})) cout<<"error";
                G_bak.erase({i,j});
            }else if(map[i][j]=='H' && (map[i+1][j]!='Z' && map[i-1][j]!='Z')){
//                if(!H_bak.erase({i,j})) cout<<"error";
                H_bak.erase({i,j});
            }
        }
    }

    for(auto g:G){
        int i =g.first,j=g.second;
        bool flag=true;
        while(flag){
            for(int k=0;k<3;k++){
                i--;
                j+=1;
                if((i<1||j>n)||map[i][j]=='Z'){
                    flag=false;
                    break;
                }
                if(map[i][j]=='G'){
                    G_bak.erase({i,j});
                }else if(map[i][j]=='H'){
                    H_bak.erase({i,j});
                }
            }
            if(!flag){
                break;
            }
            for(int k=0;k<4;k++){
                i--;
                j-=1;
                if((i<1||j<1)||map[i][j]=='Z'){
                    flag=false;
                    break;
                }
                if(map[i][j]=='G'){
                    G_bak.erase({i,j});
                }else if(map[i][j]=='H'){
                    H_bak.erase({i,j});
                }
            }
        }
    }

    for(auto h:H_bak){
        int j=h.second;
        for(int i=h.first-1;i>=1;i--){
            if(map[i][j]=='*'&& (map[i+1][j]!='Z' && map[i-1][j]!='Z')){
                safe.erase({i,j});
            }
        }
    }

    for(auto g:G_bak){
        int i =g.first,j=g.second;
        bool flag=true;
        while(flag){
            for(int k=0;k<3;k++){
                i--;
                j+=1;
                if((i<1||j>n)||map[i][j]=='Z'){
                    flag=false;
                    break;
                }
                if(map[i][j]=='*'){
                    safe.erase({i,j});
                }
            }
            if(!flag){
                break;
            }
            for(int k=0;k<4;k++){
                i--;
                j-=1;
                if((i<1||j<1)||map[i][j]=='Z'){
                    flag=false;
                    break;
                }
                if(map[i][j]=='*'){
                    safe.erase({i,j});
                }
            }
        }
    }
    if(safe.size() == 0){
        cout<<"War is Peace.";
    }else{
        cout<<safe.size();
    }
    fclose(stdin);
}
