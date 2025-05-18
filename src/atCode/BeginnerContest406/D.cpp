#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


void solve() {
    int h,w,n;
    cin>>h>>w>>n;
//    vector<unordered_set<int>> mp1(h+1, unordered_set<int>());
//    vector<unordered_set<int>> mp2(w+1, unordered_set<int>());
    vector<vector<int>> row(h+1), col(w+1);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    vector<bool> rmRow(h+1, false), rmCol(w+1, false);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int op,x;
        cin>>op>>x;
        if(op==1){
            if (rmRow[x]) {
                cout << 0 << endl;
            } else {
                int cnt = 0;
                for (int y: row[x]) {
                    if (!rmCol[y]) cnt++;
                }
                rmRow[x] = true;
                cout << cnt << endl;
            }
        }
        if(op==2){
            if(rmCol[x]) {
                cout << 0 << endl;
            } else {
                int cnt = 0;
                for (int y : col[x]) {
                    if (!rmRow[y]) cnt++;
                }
                rmCol[x] = true;
                cout << cnt << endl;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginnerContest406/in/D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}