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
void add_edge(int from,int to,int cost){
    e[ecnt].from=from;
    e[ecnt].to=to;
    e[ecnt].cost=cost;
    e[ecnt].next=head[from];
    head[from]=ecnt++;
}

void add_highway(Node* nodes,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cost = pow(nodes[i].x-nodes[j].x,2)+pow(nodes[i].y-nodes[j].y,2);
            add_edge(i,j,cost);
            add_edge(j,i,cost);
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){

    }
}