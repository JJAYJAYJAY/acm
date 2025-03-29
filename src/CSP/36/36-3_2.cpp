//
// Created by lyh on 2025/3/26.
//
#include <iostream>
#include<vector>
#include <cstring>
#include <map>

using namespace std;
const int C = 65546;
struct memory{
    int id;
    bool is_change = false;
    int next_id=-1;
    int pre_id=-1;
};

vector<memory> memories[C];
map<int,int> id_map;
int latest[C],oldest[C],m_size[C];
int n,N,q;

int get_group(int id){
    return (id/n)%N;
}


void delete_node(int group,int group_id){
    memory &m = memories[group][group_id];
    int prev = m.pre_id,next = m.next_id;
    if(prev != -1){
        memories[group][prev].next_id = next;
    }
    if(next != -1){
        memories[group][next].pre_id = prev;
    }
    if(oldest[group] == group_id){
//        cout<<"前移"<<endl;
//        cout<<oldest[group] <<endl;
        oldest[group] = prev;
    }
    if(latest[group]==group_id){
        latest[group]=next;
    }
    id_map[m.id] = 0;
}

void add_node(int group,int group_id){
    memory &m = memories[group][group_id];
    m.next_id = latest[group];
    m.pre_id = -1;
    if(latest[group]!=-1)
        memories[group][latest[group]].pre_id = group_id;
    if(oldest[group]==-1)
        oldest[group] = group_id;
    latest[group] = group_id;
    id_map[m.id] = group_id;
}

void replace_the_latest(int id){
//    cout<<"发生替换"<<id<<endl;
    int group = get_group(id);
    memory &oldest_m = memories[group][oldest[group]];
    if(oldest_m.is_change) {
        //进行内存写入
        cout<<1<<" "<<oldest_m.id<<endl;
    }
    int oldest_id = oldest[group];
    delete_node(group,oldest_id);
    memories[group][oldest_id].id = id;
    add_node(group,oldest_id);
    //创建id到下标的映射
    memories[group][id_map[id]].is_change = false;
    cout<<0<<" "<<id<<endl;
}

bool find(int id){
    if(id_map[id]!=0){
        return true;
    }
    return false;
}

void update_latest(int id){
    int group_id = id_map[id];
    int group = get_group(id);
    delete_node(group,group_id);
    add_node(group,group_id);
};

void read(int id,bool flag = true){
    int group = get_group(id);
    if(flag&&find(id)){
        update_latest(id);
        return;
    }else{
        if(m_size[group]<=n){
            id_map[id] = m_size[group];
            memories[group].push_back({id,false,-1,-1});
            add_node(group,m_size[group]);
            m_size[group]++;
            cout<<0<<" "<<id<<endl;
        }else{
            replace_the_latest(id);
        }
    }

}

void write(int id){
    int group = get_group(id);
    if(find(id)){
        memory &m = memories[group][id_map[id]];
        m.is_change = true;
        update_latest(id);
        return;
    }else{
        if(m_size[group]<=n){
            read(id,false);
        }else{
            replace_the_latest(id);
        }
    }
    memories[group][id_map[id]].is_change = true;
}

int main(){
    scanf("%d%d%d",&n,&N,&q);
    memset(latest,-1, sizeof latest);
    memset(oldest,-1, sizeof oldest);
    for(int i=0;i<C;i++){
        memories[i].push_back({-1,false,-1,-1});
        m_size[i] = 1;
    }

    while(q--){
        int op,id;
        scanf("%d%d",&op,&id);
//        cout<<"操作"<<op<<" "<<id<<endl;
        if(op==0){
            read(id);
        }else{
            write(id);
        }
//        cout<<memories[0].size()<<endl;
//        cout<<oldest[0]<<endl;
    }
}
