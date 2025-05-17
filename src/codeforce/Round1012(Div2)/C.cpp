#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

struct Node {
    int x, y, dis, id, in_id;
    bool operator< (const Node& other) const {
        if(dis!=other.dis){
            return dis<other.dis;
        }
        if(x!=other.x){
            return x<other.x;
        }
        return y<other.y;
    }
};
set<Node> nodes;
set<Node> nodes2;
void solve() {
    int n;
    cin>>n;
    auto nodesit = nodes.begin();
    auto nodes2it = nodes2.begin();
    vector<bool> vis(400000, false);
    for(int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        //格子id  = id*4+1+2+3
        if(x==0){
            Node t = *(nodes2it);
            while(vis[t.id*4]||vis[t.id*4+1]||vis[t.id*4+2]||vis[t.id*4+3]){
                nodes2it++;
                t = *(nodes2it);
            }
            cout<<t.x<<" "<<t.y<<endl;
//            cout<<t.id<<endl;
            vis[t.id*4+t.in_id]=true;
            nodes2it++;
        }
        if(x==1){
            Node  t = *(nodesit);
            while(vis[t.id*4+t.in_id]){
                nodesit++;
                t = *(nodesit);
            }
            cout<<t.x<<" "<<t.y<<endl;
            vis[t.id*4  + t.in_id]=true;
            nodesit++;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/codeforce/Round1012(Div2)/in/C.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    cin>>work;
    for(int i=0;i<= floor(sqrt(100000));i++){
        for(int j=0;j<= floor(sqrt(100000));j++){
            int id = (int)floor(sqrt(100000))*i+j;
            int x = 3*i;
            int y = 3*j;
            nodes.insert({x+1,y+1, x+y+2, id,0});
            nodes.insert({x+1,y+2, x+y+3, id,1});
            nodes.insert({x+2,y+1, x+y+3, id,2});
            nodes.insert({x+2,y+2, x+y+6, id,3});
            nodes2.insert({x+1,y+1, x+y+2, id,0});
        }
    }
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}