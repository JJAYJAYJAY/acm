//
// Created by lyh on 2025/3/8.
//
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
const int N=1e5+10;

int n,m,p,q;

struct point{
    int x,y,id;
    point(int x, int y, int id) : x(x), y(y), id(id) {}
    point() {}
}peos[N];

map<int,map<int,int>> mp;
int dist;

bool operator < (struct point a,struct point b){
    if(a.x==b.x){
        return a.y<b.y;
    }
    return a.x<b.x;
}

unordered_map<int,set<struct point>> row,col,ld,rd;

void insert_people(struct point people){
    peos[people.id] = people;
    mp[people.x][people.y] = people.id;
    col[people.x].insert(people);
    row[people.y].insert(people);
    ld[people.x - people.y].insert(people);
    rd[people.x + people.y].insert(people);
}

void remove_people(struct point people){
    mp[people.x][people.y] = 0;
    col[people.x].erase(people);
    row[people.y].erase(people);
    ld[people.x - people.y].erase(people);
    rd[people.x + people.y].erase(people);
}

int search_dire_people(struct point q, int direction) {
    int dist = 0x3f; // 初始化为一个较大的值
    switch (direction) {
        case 1: {
            auto i = col[q.x].lower_bound(q);
            auto j = col[q.x].upper_bound(q);
            if (i != col[q.x].begin() ) {
                --i; // lower_bound 返回的是第一个不小于 q 的元素，需要前移一个
                dist = min(q.y - i->y, dist);
            }
            if(j != col[q.x].end()){
                dist = min(dist, j->y - q.y);
            }
            break;
        }
        case 2: {
            auto i = row[q.y].lower_bound(q);
            auto j = row[q.y].upper_bound(q);
            if (i != row[q.y].begin()) {
                --i;
                dist = std::min(q.x - i->x, dist);
            }
            if(j != row[q.y].end()){
                dist = min(dist, j->x - q.x);
            }
            break;
        }
        case 3: {
            int key = q.x - q.y;
            auto i = ld[key].lower_bound(q);
            auto j = ld[key].upper_bound(q);
            if (i != ld[key].begin()) {
                --i;
                dist = std::min(q.x - i->x, dist);
            }
            if(j != ld[key].end()){
                dist = min(dist, j->x - q.x);
            }
            break;
        }
        case 4: {
            int key = q.x + q.y;
            auto i = rd[key].lower_bound(q);
            auto j = rd[key].upper_bound(q);
            if (i != rd[key].begin()) {
                --i;
                dist = std::min(q.x - i->x, dist);
            }
            if(j != rd[key].end()){
                dist = min(dist, j->x - q.x);
            }
            break;
        }
    }
    return dist;
}

vector<int> search_people(struct point q){
    vector<int> res;
    int min_d1=0x3f,min_d2;
    //找最近的人
    for(int i =1;i<=4;i++){
        min_d1=min(min_d1,search_dire_people(q,i));
    }

    min_d2 = min(q.x-1,min(q.y-1,min(n-q.x,m-q.y)));

    dist = min_d2 < min_d1?0:min_d1;
    if(!dist) return res;
    int dx[8] = {1,1,0,-1,-1,-1,0,1},dy[8] = {0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<8;i++){
        res.push_back(mp[q.x + dist * dx[i]][q.y + dist * dy[i]]);
    }
    return res;
}

void change_people(vector<int> &p,int t){
    int dx[8] = {1,1,0,-1,-1,-1,0,1},dy[8] = {0,1,1,1,0,-1,-1,-1};
    vector<point> peoples;
    for(int i=0;i<8;i++){
        if(p[i]==0) continue;
        remove_people(peos[p[i]]);
        peos[p[i]].x += dist*(dx[(i + t)%8]-dx[i]);
        peos[p[i]].y += dist*(dy[(i + t)%8]-dy[i]);
        peoples.push_back(peos[p[i]]);
    }
    for(auto item : peoples){
        insert_people(item);
    }
}

int main(){
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=1;i<=p;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        struct point p=point(x,y,i);
        insert_people(p);
    }
    while(q--){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        struct point p=point(x,y,10000);
        vector<int> ps = search_people(p);
        if(!dist) continue;
        change_people(ps,t);
    }
    long long ans=0;
    for(int i=1;i<=p;i++){
        ans ^=i * peos[i].x+peos[i].y;
    }
    printf("%lld",ans);
}

