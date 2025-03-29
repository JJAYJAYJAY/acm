//
// Created by lyh on 2025/3/11.
//
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
            start=i+1;
        }
    }
    res.push_back(path.substr(start));
    return res;
}

int dfs_delete_file(vector<string> &filename, int x){
    string name = filename[x];
    if(x==filename.size()-1){
        if(s[x].count({name})){
            int size;
            if(s[x].find({name})->type==0){
                size = s[x].find({name})->size;
            }else{
                size = s[x].find({name})->posterity_total + s[x].find({name})->child_total;
            }
            s[x].erase({name});
            return size;
        }else{
            return -1;
        }
    }else{
        if(s[x].count({name})){
            int size = dfs_delete_file(filename,x+1);
            if(size==-1){
                return -1;
            }else{
                if(x==filename.size()-2 && s[x].find({name})->type==0){
                    nodes[x].child_now-=size;
                }else{
                    nodes[x].posterity_now-=size;
                }
            }
        }else{
            return -1;
        }
    }
    return 1;
}

bool delete_file(string path){
    vector<string> filename = get_filename(path);
    if(filename.size()==1){
        if(s[0].count({filename[0]})){
            Node file = *s[0].find({filename[0]});
            if(file.type==0){
                nodes[0].child_now -= file.size;
            }else {
                nodes[0].posterity_now -= file.posterity_total+file.child_total;
            }
            s[0].erase({filename[0]});
        }
    }else{
        dfs_delete_file(filename,0);
    }
    return true;
}

int dfs_create_file(vector<string> &filename,int i,int j,int size,vector<int> &new_nodes,vector<string> &create_path){
    string name = filename[i];
    create_path.push_back(name);
    if(i==filename.size()-1){
        if(nodes[j].child_now+size>nodes[j].child_total){
            return -1;
        }
        if(s[j].count({name})){
            Node file = *s[j].find({name});
            if(file.type==1) {
                return -1;
            }
            int change = size - file.size;
            nodes[file.id].size = size;
            return change;
        }else{
            Node file = {name,idx++,0,0,0,0,0,size};
            s[j].insert(file);
            nodes[idx-1] = file;
            new_nodes.push_back(idx-1);
            return size;
        }
    }else{
        if(s[j].count({name})){
            if(s[j].find({name})->type==0){
//                delete_file(create_path,new_nodes);
               return -1;
            }
            if(nodes[j].posterity_now+size>nodes[j].posterity_total) {
//                delete_file(create_path,new_nodes);
                return -1;
            }
            auto change = dfs_create_file(filename,i+1,s[j].find({name})->id,size,new_nodes,create_path);
            if(change==-1){
                return change;
            };
            nodes[j].posterity_now+=change;
        }else{
            if(nodes[j].posterity_now+size>nodes[j].posterity_total){
                return -1;
            }else {
                nodes[j].posterity_now += size;
            }
            if(i==filename.size()-2){
                Node file ={name,idx++,0x3f3f3f3f,size,0,0,1};
                s[j].insert(file);
                nodes[idx-1] = file;
            }else{
                Node file = {name,idx++,0,0,0x3f3f3f3f,size,1};
                s[j].insert(file);
                nodes[idx-1] = file;
            }
            new_nodes.push_back(idx-1);
            dfs_create_file(filename,i+1,s[j].find({name})->id,size,new_nodes,create_path);
       }
    }
    return true;
}

bool create_file(string path,int size) {
    vector<string> filename = get_filename(path);
    vector<int> new_nodes;
    vector<string> create_path;
//    if(filename.size()==1){
//
//    }else{
        if(dfs_create_file(filename,0,0,size,new_nodes,create_path)==-1){
            return false;
        };
//    }
    return true;
}

void dfs_recover(vector<string> change_path,set<int> change_id,long long change,Node backup){
    int root = 0;
    for(int i=0;i<change_path.size();i++){
        string name = change_path[i];
        auto it  = s[root].find({name});
        if(i==change_path.size()-1){
            nodes[it->id] = backup;
        }else{
            if(change_id.count(it->id)) nodes[it->id].posterity_now-=change;
        }
        root = it->id;
    }
}

pair<long long,Node> dfs_update(vector<string> filename,long long child_total,long long posterity_total,int i,int j,set<int> &change_id){
    string name = filename[i];
    if(name == "/"){
        if(nodes[0].posterity_now>posterity_total || nodes[0].child_now>child_total){
            return pair<long long,Node> {-1,Node{}};
        }else{
            nodes[0].posterity_total = posterity_total;
            nodes[0].child_total = child_total;
            return pair<long long,Node> {posterity_total+child_total,nodes[0]};
        }
    }
    if(!s[j].count({name})){
        return pair<long long,Node> {-1,Node{}};
    }
    if(i == filename.size()-1){
        if(s[j].find({name})->type==0){
            return pair<long long,Node> {-1,Node{}};
        }else{
            int id = s[j].find({name})->id;
            if(nodes[id].posterity_now<posterity_total || nodes[id].child_now<child_total){
                return pair<long long,Node> {-1,Node{}};
            }else{
                long long change=0;
                if(nodes[id].posterity_total == 0x3f3f3f3f){
                    change += posterity_total + child_total;
                }else{
                    change += posterity_total- nodes[id].posterity_total;
                }
                if(nodes[id].child_total == 0x3f3f3f3f){
                    change += child_total;
                }else{
                    change += child_total - nodes[id].child_total;
                }
                Node backup = {nodes[id].name,nodes[id].id,nodes[id].child_total,nodes[id].child_now,nodes[id].posterity_total,nodes[id].posterity_now,nodes[id].type,nodes[id].size};
                nodes[id].posterity_now = posterity_total;
                nodes[id].posterity_total = posterity_total;
                change_id.insert(id);
                return pair<long long,Node> {change,backup};
            }
        }
    }else{
        auto change = dfs_update(filename,child_total,posterity_total,i+1,s[j].find({name})->id,change_id);
        if(change.first==-1){
            return change;
        }else{
            if(nodes[j].posterity_total < nodes[j].posterity_now + change.first){
                dfs_recover(filename,change_id,change.first,change.second);
                return {-1,Node{}};
            }else{
                if(nodes[j].posterity_total != 0x3f3f3f3f){
                    nodes[j].posterity_now += change.first;
                    change_id.insert(j);
                }
                return change;
            }
        }
    }
}


bool update_file(string path,long long child_total,long long posterity_total) {
    vector<string> filename = get_filename(path);
    set<int> change_id;
    auto change = dfs_update(filename,child_total,posterity_total,0,0,change_id);
    if(change.first==-1){
        return false;
    }else{
        return true;
    }
}

int main(){
    Node root = {"root",0,0x3f3f3f3f,0,0x3f3f3f3f,0,1};
    s[idx].insert(root);
    nodes[idx++] = root;

    int n;
    scanf("%d",&n);
    while(n--){
        char op[2];
        scanf("%s",op);
        if(op[0]=='C'){
            string path;
            int size;
            cin>>path>>size;
            if(create_file(path,size)){
                printf("Y\n");
            }else{
                printf("N\n");
            }
        }else if(op[0]=='R'){
            string path;
            cin>>path;
            if(delete_file(path)){
                printf("Y\n");
            }
        }else{
            string path;
            long long child_total,posterity_total;
            cin>>path>>child_total>>posterity_total;
            if(update_file(path,child_total,posterity_total)){
                printf("Y\n");
            }else{
                printf("N\n");
            }
        }
    }
    return  0;
}

