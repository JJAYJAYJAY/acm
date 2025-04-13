#include <iostream>
#include <set>

using namespace std;
struct node{
    int x,y;
    bool operator<(const node &a) const {
        if(y-x!=a.y-a.x) return y-x>a.y-a.x;
        return x < a.x || (x == a.x && y < a.y);
    }
};
set<node> s;
set<node> used;
int n;
void solve() {
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        s.insert({x,y});
    }
    int cnt = 0;
    while(!s.empty()){
        auto it = s.begin();
        int x = it->x;
        int y = it->y;
        s.erase(it);
        if(!used.count({x,y})){
            cnt++;
        }
        if(s.count({x+1,y+1})&&!used.count({x+1,y+1})){
            used.insert({x+1,y+1});
        }
        else if(s.count({x+1,y})&&!used.count({x+1,y})){
            used.insert({x+1,y});
        }
        else if(s.count({x+1,y-1})&&!used.count({x+1,y-1})){
            used.insert({x+1,y-1});
        }

    }
    cout<<cnt<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/MX-J13/in/T595153.in", "r", stdin);
#endif
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}