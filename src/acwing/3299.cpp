//
// Created by lyh on 2025/3/10.
//
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int N =1e5+10;

int n;

struct Node{
    string name;
    int id;
    long long child_total,child_now;
    long long posterity_total,posterity_now;
    int type;
    int size;
    bool operator < (const Node &a) const{
        return name<a.name;
    }
};

set<Node> s[N];
Node nodes[N];
int idx;
vector<string> get_filename(string path){
    vector<string> res;
    int start=1;
    for(int i=1;path[i];i++){
        if(path[i]=='/') {
            string name = path.substr(start,i-start);
            res.push_back(name);
        }
    }
    return res;
}

bool create_file(int dir_id,int size,int type,string name,bool final_dir=0){
    if(!type){
        if(nodes[dir_id].child_now+size>nodes[dir_id].child_total){
            return false;
        }else{
            nodes[dir_id].child_now+=size;
            s[dir_id].insert({name,idx++,0,0,0,0,0,size});
        }
    }else{
        if(nodes[dir_id].posterity_now+size>nodes[dir_id].posterity_total){
            return false;
        }else{
            nodes[dir_id].posterity_now+=size;
            if(final_dir){
                s[dir_id].insert({name,idx++,size,size,0,0,1});
            }else {
                s[dir_id].insert({name, idx++, 0, 0, size, size, 1});
            }
        }
    }
    return true;
}

int delete_file(vector<pair<string,int>> path , int x){
    //如果找不到直接返回0
    if(!s[path[x-1].second].count({path[x].first})){
        return 0;
    }
    if(x==path.size()-1){
        int size = s[path[x-1].second].find({path[x].first})->size;
        s[path[x-1].second].erase({path[x].first});
        return size;
    }
    int size = delete_file(path,x+1);
    if(x==path.size()-2){
        nodes[path[x].second].child_now-=size;
    }
//    else{
//        nodes[path[x].second].posterity_now-=size;
//    }
    return size;
}

bool dfs_delete_file(vector<pair<string,int>> path){
   if(path.size()==1){
       if(s[0].count({path[0].first})){
           int size = s[0].find({path[0].first})->size;
           s[0].erase({path[0].first});
           nodes[0].child_now-=size;
       }
   }else{
       delete_file(path,1);
   }
   return true;
}


bool dfs_create_file(string path,int size) {
    vector<string> filename = get_filename(path);
    vector<pair<string,int>> record;
    int root = 0;
    for(int i = 0;i<filename.size();i++){
       string name =filename[i];
       bool flag;
        if(!s[root].count({name})){
            if(i==filename.size()-1){
                flag = create_file(root,size,0,name);
            }else if(i==filename.size()-2){
                flag = create_file(root,size,1,name,1);
            }else{
                flag = create_file(root,size,1,name);
            }
            if(flag){
                record.push_back({name, 1});
            }else{
                dfs_delete_file(record);
            }
        }else{
            auto it=s[root].find({name});
            if(it->type==1) {
                dfs_delete_file(record);
                return false;
            }
            root=it->id;
            record.push_back({name,0});
        }
    }
    return true;
}

long long dfs_update(string path,long long child_total,long long posterity_total,int x){
    if(!s[path[x-1].second].count({path[x].first})){
        return -1;
    }
    if(x==path.size()-1){
    }
    long long size = dfs_update(path,child_total,posterity_total,x+1);
    return size;
}

bool update_file(string path,long long child_total,long long posterity_total) {
    vector<string> filename = get_filename(path);
    int root = 0;
    return true;
}

int main(){
    Node root = {"root",0,0x3f3f3f3f,0,0x3f3f3f3f,0,1};
    s[idx].insert(root);
    nodes[idx++] = root;


    return  0;
}