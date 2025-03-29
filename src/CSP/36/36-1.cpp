//
// Created by lyh on 2025/3/25.
//
#include<iostream>

using namespace std;

int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    while(k--){
        int x,y;
        scanf("%d%d",&x,&y);
        char op[110];
        scanf("%s",op);
        int a,b;
        for(int i=0;op[i];i++){
            if(op[i]=='f'){
               a = dx[0],b = dy[0];
            }if(op[i]=='b'){
                a = dx[1],b = dy[1];
            }if(op[i]=='l'){
                a = dx[2],b = dy[2];
            }if(op[i]=='r'){
                a = dx[3],b = dy[3];
            }
            if(x+a>=1&&x+a<=n&&y+b>=1&&y+b<=n){
                x+=a;
                y+=b;
            }
        }
        printf("%d %d\n",x,y);
    }
}