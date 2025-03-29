//
// Created by lyh on 2025/3/26.
//
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int C = 65546;
struct memory{
    int id;
    bool is_change = false;
    int next_id=-1;
    int pre_id=-1;
};


map<int,memory> memories[C];
int latest[C],oldest[C];
map<int,int> id_to_group_id;
int n,N,q;

void replace_the_latest(int id){
    int group = (id/n)%N,group_id = oldest[group];
    memory &m = memories[group][oldest[group]];
    if(m.is_change) {
        //进行内存写入
        cout<<1<<" "<<m.id<<endl;
    }
    oldest[group] = m.pre_id;
    m.next_id = latest[group];
    m.pre_id = -1;
    memories[group][latest[group]].pre_id = group_id;
    latest[group] = group_id;
    id_to_group_id.erase(m.id);
    m.id = id;
    m.is_change = false;
    id_to_group_id.insert({id,group_id});
    cout<<0<<" "<<id<<endl;
}

bool find(int id){
    if(memories[(id/n)%N].count(id)){
        return true;
    }
    return false;
}

void update_latest(int id){
    int group = (id/n)%N,group_id = id_to_group_id[id];

    memory &m = memories[group][group_id];
    if(group_id == oldest[group]){
        oldest[group] = m.pre_id;
    }
    int prev = m.pre_id,next = m.next_id;
    if(prev != -1){
        memories[group][prev].next_id = next;
        return;
    }
    if(next != -1){
        memories[group][next].pre_id = prev;
        return;
    }

    if(latest[group] != -1){
        memories[group][latest[group]].pre_id = group_id;
        m.next_id = latest[group];
    }
    m.pre_id = -1;
    latest[group] = group_id;
    if(oldest[group] == -1){
        oldest[group] = group_id;
    }
};

void read(int id,bool flag = true){
    int group = (id/n)%N;
    if(flag && find(id)) {
        //更新最近访问的内存
        update_latest(id);
        return;
    }else{
        if(memories[group].size()+1<n){
            //直接读取内存
            id_to_group_id[id] = memories[group].size();
            memories[group].insert({memories[group].size(),{id,false,-1,-1}});
            update_latest(id);
            cout<<0<<" "<<id<<endl;
        }else{
            replace_the_latest(id);
        }
    }
}

void write(int id){
    int group = (id/n)%N,group_id = id;
    if(find(id)){
        memory &m = memories[group][group_id];
        m.is_change = true;
        update_latest(id);
        return;
    }else{
        if(memories[group].size()<n){
            //直接写入内存
            read(id, false);
        }else{
            replace_the_latest(id);
        }
    }
    memory &m = memories[group][group_id];
    m.is_change = true;
}

int main(){
    scanf("%d%d%d",&n,&N,&q);
    memset(latest,-1, sizeof latest);
    memset(oldest,-1, sizeof oldest);
    while(q--){
        int op,id;
        scanf("%d%d",&op,&id);
        if(op==0){
            read(id);
        }else{
            write(id);
        }
//        cout<<memories[0].size()<<endl;
//        cout<<oldest[0]<<endl;
    }
}
