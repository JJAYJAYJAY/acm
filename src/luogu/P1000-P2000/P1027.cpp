//
// Created by lyh on 2024/9/15.
//
#include "iostream"
#include <math.h>

using namespace std;

struct Edge{
    int from,to,cost,next;
}e[100000];

struct Node{
    int x,y;
};

int ecnt=0;
int head[10000];
void add_edge(int from,int to,int dis,int cost){
    e[ecnt].from=from;
    e[ecnt].to=to;
    e[ecnt].cost=cost*dis;
    e[ecnt].next=head[from];
    head[from]=ecnt++;
}



int main(){
    int n;
    scanf("%d",&n);
    int s,t,a,b;
    int x1,y1,x2,y2,x3,y3,r_c;
    Node city[100][4];
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&s,&t,&a,&b);
        for(int j=0;j<s;j++){
            scanf("%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&r_c);
            
            //添加边
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    if(k!=l){
                        add_edge(i*4+k,i*4+l,sqrt(pow(city[i][k].x-city[i][l].x,2)+pow(city[i][k].y-city[i][l].y,2)),r_c);
                    }
                }
            }
        }
        //city之间的边

    }
}