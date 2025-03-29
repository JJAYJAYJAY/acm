//
// Created by lyh on 2025/3/28.
//
#include <iostream>
#include<set>
#include <map>
using namespace std;

const int N = 5010;
struct node{
    int id,num;
    set<int> task;
    bool operator < (const node &t) const{
        if(num == t.num){
            return id<t.id;
        }
        return num<t.num;
    }
};

struct area{
    set<int> task;
    set<node> nodes;
}area[N];

map<int,int> node_area;
int n,m,g;


void add_task(int node_id,int task_id,int task_num ){
    int area_id = node_area[node_id];
    area[area_id].task.insert(task_id);
    auto it = area[area_id].nodes.find({node_id,task_num});
    node node = *it;
//    cout<<"find:"<<node.id<<endl;
    area[area_id].nodes.erase(it);
    //修改
    node.task.insert(task_id);
    node.num+=1;
    //插入
    area[area_id].nodes.insert(node);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int l;
        scanf("%d",&l);
        area[l].nodes.insert({i,0});
        node_area.insert({i,l});
    }
//    cout<<"完成录入"<<endl;
//    for(auto &item:node_area){
//        cout<<item.first<<" "<<item.second<<endl;
//    }
    scanf("%d",&g);
    while(g--){
        int f,a,na,pa,paa,paar;
        scanf("%d%d%d%d%d%d",&f,&a,&na,&pa,&paa,&paar);
        set<int> areas1;
        if(na==0){
            for(int i=1;i<=m;i++){
                areas1.insert(i);
            }
        }else{
            areas1.insert(na);
        }
        if(pa!=0){
            for (auto it = areas1.begin(); it != areas1.end(); ) {
                if (!area[*it].task.count(pa)) {
                    it = areas1.erase(it);
                } else {
                    ++it;
                }
            }
        }
        set<node> nodes;
        for(auto &item:areas1){
            for(auto &node:area[item].nodes){
                nodes.insert(node);
            }
        }
        //备份一个nodes
        set<node> nodes1 = nodes;
        set<node> nodes2;
        if(paa!=0){
            for(auto it = nodes1.begin();it!=nodes1.end();) {
                if (it->task.count(paa)) {
                    nodes2.insert(*it);
                    it = nodes1.erase(it);
                } else {
                    it++;
                }
            }
            if(paar==1){
                nodes = nodes1;
            }
            if(paar==0 && nodes1.size()>0){
                nodes = nodes1;
            }
        }

        while(f--){
            if(nodes.empty()){
                cout<<0<<" ";
                continue;
            }
            auto it = nodes.begin();
            cout<<it->id<<" ";
            add_task(it->id,a,it->num);
//            cout<<area[node_area[it->id]].nodes.find({it->id})->id<<" ";
            node node = *area[node_area[it->id]].nodes.find({it->id,it->num+1});
            nodes.erase(it);
//            cout<<node.id<<" "<<endl;
//            cout<<"find:"<<node.task.count(paa)<<endl;
            if(paar==1 && node.task.count(paa)){

            }
            else if(!node.task.count(paa)){
                nodes.insert(node);
            }
            else if(node.task.count(paa)){
                nodes2.insert(node);
            }
            if(paar==0 && nodes.empty()){
                nodes = nodes2;
                nodes2.clear();
            }
        }
        cout<<endl;
    }

}
